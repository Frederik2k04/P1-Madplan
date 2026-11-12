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
        printf("cannot open backend/data/stores.txt. \n");
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
    printf("the three stores were selected outside the program. \n");

        for (int store_id = 1; store_id <= MAX_STORES; store_id = store_id +1) {

    printf("%d. %s\n", store_id, stores[store_id].name);
    printf("%s\n", stores[store_id].address);
    printf("Saved walking distance: %d m\n", stores[store_id].walking_meters);
                }
    printf("Water is assumed available at home\n");
                } 
