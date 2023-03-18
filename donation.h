#ifndef __DONATION_H__
#define __DONATION_H__
#include "csv.h"

typedef struct {    
    int day; 
    int month;
    int year;
} tDate;


// Parse a tDate from string information
void date_parse(tDate* date, const char* text);

// Compare two tDate structures and return true if they contain the same value or false otherwise.
bool date_equals(tDate date1, tDate date2);


///////////////////////////
// Constants

// Maximum length of project code
#define MAX_PROJECT_CODE 7
// Maximum length of a ngo code
#define MAX_NGO_CODE 3
// Maximum length of an id document
#define MAX_DOC_ID 9

//////////////////////////////////
// Ex 1: Define data types here...

#define MAX_DONATIONS 120

typedef struct {
    tDate date;
    char document[50];
    char ngo[3];
    char projectCode[50];
    double amount;
}tDonation;

typedef struct { //ordenades pel codi del projecte
    tDonation donationsTable[MAX_DONATIONS];
    int n;
}tDonationData;

//////////////////////////////////
// Ex 2: Define your methods here ....


// Initialize the donations data 

void donationData_init(tDonationData *data);

// Get the number of donations
int donationData_len (tDonationData data);

// Parse input from CSVEntry
void donation_parse (tDonation* donation, tCSVEntry entry);

// Add a new donation
void donationData_add (tDonationData* data, tDonation donation);

// Get a donation
void donationData_get (tDonationData data, int index, char* buffer);

// Remove a donation
void donationData_del(tDonationData *data, tDate date, char projectCode[], char document[]);


////////////////////////////////////////////
// Auxiliary Methods


////////////////////////////////////////////

#endif
