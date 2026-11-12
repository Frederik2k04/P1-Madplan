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
            fclose(file);
            return 0;
        }

        read_text(file, recipes[recipe_id].name, 80);
        recipes[recipe_id].loaded = 1;

        values_read = fscanf(file, "%d", &recipe_id);
    }

    if (values_read != EOF) {
        printf("Check entry %d in recipes.txt.\n", number + 1);
        fclose(file);
        return 0;
    }

    fclose(file);

    return 1;
}


int load_ingredients(Recipe recipes[])
{
    FILE *file;
    int number;
    int recipe_id = 0;
    int item_id = 0;
    int amount;
    int values_read;
    int entry_ok;

    file = fopen("backend/data/ingredients.txt", "r");

    if (file == NULL) {
        printf("cannot open backend/data/ingredients.txt\n");
        return 0;
    }

    number = 0;
    values_read = fscanf(file, "%d %d %d", &recipe_id, &item_id, &amount);

    while (values_read == 3) {
        number = number + 1;
        entry_ok = 1;

        if (recipe_id < 1 || recipe_id > MAX_RECIPES) {
            entry_ok = 0;
        }

        if (item_id < 1 || item_id > MAX_ITEMS) {
            entry_ok = 0;
        }

        if (entry_ok == 0) {
            printf("check entry %d in ingredients.txt\n", number);
            fclose(file);
            return 0;
        }

        recipes[recipe_id].amount[item_id] = amount;
        values_read = fscanf(file, "%d %d %d", &recipe_id, &item_id, &amount);
    }

    if (values_read != EOF) {
        printf("check entry %d in ingredients.txt\n", number + 1);
        fclose(file);
        return 0;
    }
    
    fclose(file);

    return 1;
}

int load_instructions(Recipe recipes[])
{
    FILE *file;
    int number;
    int recipe_id = 0;
    int step_number = 0;
    int values_read;
    int entry_ok;

    file = fopen("backend/data/instructions.txt", "r");

    if (file == NULL){
        printf("cannot open backend/data/instructions.txt\n");
        return 0 ;
    }

    number = 0;
    values_read = fscanf (file, "%d %d", &recipe_id, &step_number);

    while (values_read == 2) {
        number = number + 1;
        entry_ok = 1;

        if (recipe_id < 1 || recipe_id > MAX_RECIPES) {
            entry_ok = 0;
        }

        if (step_number < 1 || step_number > MAX_STEPS){
            entry_ok = 0;
        }

        if (entry_ok == 0) {
            printf("check entry %d in instructions.txt\n", number);
            fclose(file);
            return 0;
        }

        read_text(file, recipes[recipe_id].instructions[step_number], 320);
        recipes[recipe_id].instruction_count = step_number;

        values_read = fscanf(file, "%d %d", &recipe_id, &step_number);
    }

    if (values_read != EOF) {
        printf("check entry %d in instructions.txt\n", number + 1);
        fclose(file);
        return 0;
    }

    fclose(file);

    return 1;
}
