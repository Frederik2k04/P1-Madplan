#ifndef FUNCTIONS_H
#define FUNCTIONS_H


int missing_amount(int need, int stock);
int count_packages(int missing, int package_amount);
int price_for_item(int need, int stock, int package_amount, int package_price);
int read_number(char prompt[], int minimum, int maximum);

#endif
