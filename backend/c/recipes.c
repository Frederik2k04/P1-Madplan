#include "functions.h"
#include <stdio.h>

int load_recipes(Recipe recipes[])
{
    FILE *file;
    int number;
    int recipe_id = 0;
    int values_read;
    int entry_ok;

    file = fopen("backend/data/recipes.txt", "r");

    if (file == NULL) {
        printf("Cannot open backend/data/recipes.txt. Run from the project root.\n");
        return 0;
    }

    number = 0;
    values_read = fscanf(file, "%d", &recipe_id);

    while (values_read == 1) {
        number = number + 1;
        entry_ok = 1;

        if (recipe_id < 1 || recipe_id > MAX_RECIPES) {
            entry_ok = 0;
        }

        if (entry_ok == 0) {
            printf("Check entry %d in recipes.txt.\n", number);
    }



}
