#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#define LINE_SIZE 2048

/* This header declares the functions implemented in price.c.
   Use the same unit for all quantities of one item. Prices are integer ore. */
int missing_amount(int need, int stock);

int price_for_item(int need, int stock, int item, int price_cent);

int read_line(char text[], int capacity);

int count_packages (int missing, int package_amount);

int parse_number (const char text [], int minimum, int maximum, int *number);

int read_number(const char prompt [], int minimum, int maximum, int*number);

int next_data_line(FILE *file, char line [], int capacity, int* line_number);

#endif



