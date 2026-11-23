#include "functions.h"
#include <stdio.h>
#include "price.c"
#include "recipes.c"
#include "terminal.c"
#include "catalog.c"


// Gør så "kr" er accepteret. + budget printf
int read_budget(int maximum)
{
    int number;
    int values_read;
    int character;
    int valid;

    valid = 0;

    while (valid == 0) {
        printf("Your budget in DKK:\n");
        values_read = scanf("%d", &number);

        if (values_read == EOF) {
            return -1;
        }

        character = getchar();

        while (character != '\n' && character != EOF) {
            character = getchar();
        }

        if (values_read != 1) {
            printf("Start with a whole number, try again.\n");
        } else if (number < 0 || number > maximum) {
            printf("The budget must be within the limit, try again.\n");
        } else {
            valid = 1;
        }
    }

    return number;
}


// primær lommeregner funktionen.
int run_calculation(Item items[], Store stores[], Recipe recipes[])
{
int recipe_id;
int budget_kr;
int include_spices;
int budget_cent;
int store_id;
int needed[MAX_ITEMS +1] = {0};
int stock[MAX_ITEMS + 1] = {0};
int totals[MAX_STORES + 1] = {0};
int selected_ids[MAX_ITEMS + 1] = {0};
int again;
int people;

recipe_id = choose_recipe(recipes);
    if (recipe_id == -1) {
        return -1;
                }
    if (recipe_id == 0) {
        return 0;
                }
show_recipe(recipes[recipe_id], items);

people = read_number("How many people are eating?:", 1, 100);
if (people == -1) {
        return -1;
                }

budget_kr = read_budget(10000);
if (budget_kr == -1) {
return -1;
                }

budget_cent = budget_kr * 100;

include_spices = read_number("Need to buy spices? (1 = yes, 0 = no):", 0, 1);
if (include_spices == -1) {
        return -1;
                }
if (include_spices == 0) {
        printf ("Spices assumed at home, not included in total price.\n");
                }

if (choose_replacements(recipes[recipe_id], items, include_spices, selected_ids) == 0) {
        return -1;
                }
build_needs(recipes[recipe_id], items, include_spices, selected_ids, needed);

for (int item_id = 1; item_id <= MAX_ITEMS; item_id = item_id + 1) {
        needed[item_id] = (needed[item_id] * people + 1) / 2;
                }

if (read_stock(items, needed, stock) == 0) {
        return -1;
                }

for (int id = 1; id <= MAX_STORES; id = id +1) {
    totals [id] = calculate_store(items, needed, stock, id);
                }
show_comparison(stores, totals, budget_cent);
store_id = choose_store(totals);

if (store_id == -1) {
    return -1;
                }
if (store_id == 0) {
    return 0;
                }

show_receipt(stores[store_id], items, needed, stock, store_id);
show_instructions(recipes[recipe_id], items, selected_ids);

again = read_number("Try again? (1 = yes, 0 = exit):", 0, 1);
if (again == -1) {
        return -1;
                }
return again;

                }




int main(void) {
    Item items[MAX_ITEMS + 1] = {0};
    Store stores[MAX_STORES + 1] = {0};
    Recipe recipes[MAX_RECIPES + 1] = {0};
    char address [160];
    int result;

if (load_stores (stores)== 0) {
return 1;

                }
if (load_items(items) == 0) {
        return 1;
                }

if (load_prices(items) == 0) {
        return 1;
                }

if (load_recipes(recipes) == 0) {
        return 1;
                }

if (load_ingredients(recipes) == 0) {
        return 1;
                }

if (load_instructions(recipes) == 0) {
        return 1;
                }

if (read_address(address) == 0) {
        return 1;
                }
if (load_replacements(items) == 0) {
        return 1;
                }
                
show_context(stores, address);

result = 1;
while (result == 1) {
        result = run_calculation(items, stores, recipes);
                }
if (result == -1) {
    return 1;
                }

return 0;

                }


