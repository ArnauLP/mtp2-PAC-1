#include <stdio.h>
#include "csv.h"
#include "donation.h"


void donationData_print_src(tDonationData data) {
    char buffer[1024];
    int i;
    if (donationData_len(data) > 0) {
        for (i = 0; i < donationData_len(data); i++) {
            donationData_get(data, i, buffer);
            printf("%d;%s\n", i, buffer);
        }
    }
}

int main(int argc, char **argv) {
    tCSVData test_data;
    tDonationData donationData;
    tDonation donation;
    tDate date;
    int i;

    // Define test data
    const char *test_data_str = \
          "15/04/2023;12345678N;ACN;ACN8455;15.50\n" \
          "30/12/2022;55755010C;CRJ;CRJ0333;3500.60\n" \
          "11/12/2022;76203765G;MSF;MSF0012;600.20\n";

    const char *test_data2_str = \
          "25/08/2022;87654321B;MSF;MSF0000;100.00\n" \
          "12/05/2022;65239334J;GRP;GRP0020;23.00\n";

    const char *test_data3_str = \
          "30/12/2022;55755010C;CRJ;CRJ0333;3500.60\n";

    // Read the data in CSV format
    csv_init(&test_data);
    csv_parse(&test_data, test_data_str, "DONATION");

    // Initialize the donations data
    donationData_init(&donationData);

    // Add data
    for (i = 0; i < csv_numEntries(test_data); i++) {
        // Get the donation from the entry
        donation_parse(&donation, csv_getEntry(test_data, i)[0]);

        // Add new donation to the list of donations
        donationData_add(&donationData, donation);
    }

    // List current donations
    printf("\n");
    donationData_print_src(donationData);
    printf("\n");

    // Remove old data
    csv_free(&test_data);

    // Load new data
    csv_init(&test_data);
    csv_parse(&test_data, test_data2_str, "DONATION");

    // Add new data
    for (i = 0; i < csv_numEntries(test_data); i++) {
        // Get the donation from the entry
        donation_parse(&donation, csv_getEntry(test_data, i)[0]);

        // Add new donation to the list of donations
        donationData_add(&donationData, donation);
    }

    // List current donations
    donationData_print_src(donationData);
    printf("\n");

    // Remove old data
    csv_free(&test_data);

    // Load new data
    csv_init(&test_data);
    csv_parse(&test_data, test_data3_str, "DONATION");

    // Add new data
    for (i = 0; i < csv_numEntries(test_data); i++) {
        // Get the donation from the entry
        donation_parse(&donation, csv_getEntry(test_data, i)[0]);

        // Add new donation to the list of donations
        donationData_add(&donationData, donation);
    }

    // List current donations
    donationData_print_src(donationData);
    printf("\n");

    // Remove donations
    date_parse(&date, "11/12/2022");
    donationData_del(&donationData, date, "76203765G", "MSF0012");

    date_parse(&date, "12/05/2022");
    donationData_del(&donationData, date, "65239334J", "GRP0020");

    // List current donations
    donationData_print_src(donationData);
    printf("\n");

    // Remove not existing registry (the same, as now it should not exist)
    date_parse(&date, "11/12/2022");
    donationData_del(&donationData, date, "76203765G", "MSF0012");

    // List current donations
    donationData_print_src(donationData);
    printf("\n");

    // Remove CSV data
    csv_free(&test_data);

    printf("\nPress key to end...\n");
    getchar();
    return 0;
}