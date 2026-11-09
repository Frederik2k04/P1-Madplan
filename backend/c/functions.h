#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define MAX_FIELDS 7
#define FIELD_SIZE 1024
#include <stdio.h>
#define LINE_SIZE 2048
#define MAX_ITEMS 32

typedef struct {
int id;
char name [100];
char unit [4];
int is_spice;
            } Item;

typedef struct {
Item items[MAX_ITEMS];
int item_count;
            } Catalog;

int missing_amount(int need, int stock);

int price_for_item(int need, int stock, int item, int price_cent);

int read_line(char text[], int capacity);
int count_packages (int missing, int package_amount);

int parse_number (const char text [], int minimum, int maximum, int *number);

int read_number(const char prompt [], int minimum, int maximum, int*number);

int next_data_line(FILE *file, char line [], int capacity, int* line_number);

int split_fields(const char line [], char fields[] [FIELD_SIZE]);

int find_item_index(const Catalog * catalog, int id);
#endif




