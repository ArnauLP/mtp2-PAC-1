cmake_minimum_required(VERSION 3.24)
project(test2 C)

set(CMAKE_C_STANDARD 17)

add_executable(test2 main.c donation.c csv.c)
