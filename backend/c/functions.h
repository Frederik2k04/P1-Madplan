#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

int missing_amount(int need, int stock);
int count_packages(int missing, int package_amount);
int price_for_item(int need, int stock, int package_amount, int package_price);
int read_number(char prompt[], int minimum, int maximum);
int read_text(FILE *file, char text[], int capacity);
int read_address(char address[]);


#endif

#define MAX_RECIPES 8
typedef struct {
    int loaded;
    char name[80];
} Recipe;

int load_recipes(Recipe recipes[]);

