#include "functions.h"
#include <stdio.h>

int read_number(char prompt[], int minimum, int maximum)
{
    int number;
    char ending;
    int values_read;

    printf("%s\n", prompt);
    values_read = scanf("%d%c", &number, &ending);

    if (values_read != 2) {
        printf("Enter one whole number. Calculation stopped.\n");
        return -1;
    }

    if (ending != '\n') {
        printf("Press Enter directly after the number. Calculation stopped.\n");
        return -1;
    }

    if (number < minimum) {
        printf("The minimum is %d. Calculation stopped.\n", minimum);
        return -1;
    }

    if (number > maximum) {
        printf("The maximum is %d. Calculation stopped.\n", maximum);
        return -1;
    }

    return number;
}


int read_text(FILE *file, char text[], int capacity)
{
    char letter;
    int length = 0;
    int result;

    result = fscanf(file, " %c", &letter);

    while (result == 1 && letter != '\n' && length < capacity - 1) {
        text[length] = letter;
        length = length + 1;
        result = fscanf(file, "%c", &letter);
    }

    text[length] = '\0';

    if (length == 0) {
        return 0;
    }

    if (result == 1 && letter != '\n') {
        return 0;
    }

    return 1;
}

int read_address(char address[])
{
    FILE *file;
    int text_ok;

    file = fopen("backend/data/address.txt", "r");

    if (file == NULL) {
        printf("Cannot open backend/data/address.txt.\n");
        return 0;
    }

    text_ok = read_text(file, address, 160);
    fclose(file);

    if (text_ok == 0) {
        printf("Write the case address on the first line of address.txt.\n");
        return 0;
    }

    return 1;
}

int choose_recipe(Recipe recipes[])
{
    int choice;

    printf("\nCHOOSE A RECIPE\n");


    for (int recipe_id = 1; recipe_id <= MAX_RECIPES; recipe_id = recipe_id + 1){
        if (recipes[recipe_id].loaded == 1) {
            printf("%d. %s\n", recipe_id, recipes[recipe_id].name);
        }
    }
    printf("0. for exit\n");
    choice = read_number("Recipe number:", 0, MAX_RECIPES);

    if (choice <= 0){
        return choice;
    }
    if (recipes[choice].loaded == 0){
        printf("that recipe number is not in the data file\n");
        return -1;
    }
    return choice;
}

int choose_store(int totals[])
{
    int choice;

    choice = read_number("store number (0 = exit):", 0, MAX_STORES);
    if (choice <= 0) {
        return choice;
    }

    if (totals[choice] == -1) {
        printf("that store is missing a required price. program closed\n");
        return -1;
    }

    return choice;
}

int read_stock(Item items[], int needed[], int stock[])
{
    printf("\nENTER FRESH PANTRY AMOUNTS\n");

   for (int item_id = 1; item_id <= MAX_ITEMS; item_id = item_id +1) {
    if (needed[item_id] > 0) {
        int amount;

        printf("%s: need %d %s\n", items[item_id].name,
                needed[item_id], items[item_id].unit);
        amount = read_number("Amount already at home (0..100.000):", 0, 100000);

        if (amount == -1) {
            return 0;
        }

        stock[item_id] = amount;
    }
   }

   return 1;
}

int choose_replacements(Recipe recipe, Item items[], int include_spices, int selected_ids[])
{
    for (int item_id = 1; item_id <= MAX_ITEMS; item_id = item_id + 1) {
        int replacement_id;

        selected_ids[item_id] = item_id;
        replacement_id = items[item_id].replacement_id;

        if (recipe.amount[item_id] > 0 && replacement_id > 0) {
            if (include_spices == 1 || items[item_id].is_spice == 0) {
                int choice;

                printf("\n%s can be replaced with %s, using the same amount.\n",
                       items[item_id].name, items[replacement_id].name);
                choice = read_number("Replace? (1 = yes, 0 = keep original):", 0, 1);

                if (choice == -1) {
                    return 0;
                }

                if (choice == 1) {
                    selected_ids[item_id] = replacement_id;
                }
            }
        }
    }

    return 1;
}

