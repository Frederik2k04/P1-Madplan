#include "functions.h"
#include <stdio.h>

int load_stores(Store stores[])
{
    FILE*file;
    int number;
    int store_id = 0;
    int values_read;
    int entry_ok;

    file = fopen("backend/data/stores.txt", "r");
    if (file == NULL) {
        printf("cannot open backend/data/stores.txt. please try again \n");
        return 0;
                }
    number = 0;
    values_read = fscanf (file, "%d", &store_id);
    while (values_read == 1) {
    number = number +1;
    entry_ok = 1;
    if (store_id < 1 || store_id > MAX_STORES) {
        entry_ok = 0;

                }
    if (entry_ok == 0) {
        printf("Check entry %d in stores.txt \n", number);
        fclose(file);
        return 0;
                }
        
    fscanf(file, "%d", &stores[store_id].walking_meters);
        read_text(file, stores[store_id].name, 80);
        read_text(file, stores[store_id].address, 160);

        values_read = fscanf(file, "%d", &store_id);

                }

    if (values_read !=EOF) {
        printf ("Check entry %d in stores.txt and try again \n", number +1);
        fclose(file);
        return 0;
                }
    fclose(file);
    
    return 1;

                }

void show_context(Store stores[], char address[]) {
    printf("\nADDRESS\n%s\n", address);
    printf("Stores available: \n");

        for (int store_id = 1; store_id <= MAX_STORES; store_id = store_id +1) {

    printf("%d. %s\n", store_id, stores[store_id].name);
    printf("%s\n", stores[store_id].address);
    printf("Saved walking distance: %d m\n", stores[store_id].walking_meters);
                }
    printf("Water is assumed available at home\n");
                } 

int load_items(Item items[]) {
FILE *file;
int number;
int item_id = 0;
int values_read;
int entry_ok;

    file =
    fopen("backend/data/items.txt", "r");

    if (file == NULL) {
        printf("Cannot open backend/data/items.txt. Please try again.\n");
        return 0;
                }
    number = 0;
    values_read = fscanf(file, "%d", &item_id);

    while (values_read == 1) {
        number = number + 1;
        entry_ok = 1;
    if (item_id < 1 || item_id > MAX_ITEMS) {
        entry_ok = 0;

                }
    if (entry_ok == 0) {
        printf("check entry %d in items.txt.\n", number);
            fclose(file);
            return 0;
                }
    
    fscanf(file, "%s %d", items [item_id].unit, &items[item_id].is_spice);
        read_text(file, items[item_id].name, 80);

    values_read =fscanf(file, "%d", &item_id);
                }
    if (values_read != EOF) {
    printf("Check entry %d in items.txt.\n", number + 1);
        fclose(file);
        return 0;
    }
    fclose(file);
    return 1;
                }

int load_prices(Item items[]) {
FILE*file;
int number;
int item_id = 0;
int store_id = 0;
int package_amount;
int price_cent;
int values_read;
int entry_ok;

file = fopen("backend/data/prices.txt", "r");

    if (file == NULL) {
        printf("Cannot open backend/data/prices.txt. Please try again.\n");
        return 0;
                }

number = 0;
values_read = fscanf(file, "%d %d %d %d", &item_id, &store_id, &package_amount, &price_cent);


while (values_read == 4) {
        number = number + 1;
        entry_ok = 1;

    if (item_id < 1 || item_id > MAX_ITEMS) {
            entry_ok = 0;
                }

    if (store_id < 1 || store_id > MAX_STORES) {
            entry_ok = 0;
                }

    if (entry_ok == 0) {
            printf("Check entry %d in prices.txt.\n", number);
            fclose(file);
            return 0;
                }  
                
items[item_id].package_amount [store_id] = package_amount;

items[item_id].price_cent[store_id] = price_cent;

values_read = fscanf(file, "%d %d %d %d", &item_id, &store_id, &package_amount, &price_cent);
                }

    if (values_read != EOF) {
        printf("Check entry %d in prices.txt.\n", number + 1);
        fclose(file);
        return 0;
                }

    fclose(file);

    return 1;
                } 

