#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>

int missing_amount(int need, int stock);
int count_packages(int missing, int package_amount);
int price_for_item(int need, int stock, int package_amount, int package_price);
int read_number(char prompt[], int minimum, int maximum);
int read_text(FILE *file, char text[], int capacity);
int read_address(char address[]);

#define MAX_STORES 3
typedef struct {
char name [80];
char address [160];
int walking_meters;
                } Store;



int load_stores(Store stores[]);
void show_context(Store stores[], char address[]);

#define MAX_ITEMS 30
typedef struct {
char name [80];
char unit [4];
int is_spice;
int package_amount [MAX_STORES + 1];
int price_cent [MAX_STORES + 1];
                } Item;

int load_items(Item items[]);
int load_prices(Item items []);

#define MAX_RECIPES 8
typedef struct {
int loaded;
char name [80];
                } Recipe;

int load_recipes(Recipe recipes []);
#endif
