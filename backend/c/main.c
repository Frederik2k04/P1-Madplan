#include "functions.h"
#include <stdio.h>
#include "price.c"
#include "recipes.c"
#include "terminal.c"
#include "catalog.c"

int run_calculation(Item items[], Store stores[], Recipe recipes[])
{
int recipe_id;
int budget_kr;
int budget_cent;
int store_id;
int needed[MAX_ITEMS +1] = {0};
int stock[MAX_ITEMS + 1] = {0};
int totals[MAX_STORES + 1] = {0};

recipe_id = choose_recipe(recipes);
    if (recipe_id == -1) {
        return -1;
                }
    if (recipe_id == 0) {
        return 0;
                }
show_recipe(recipes[recipe_id], items);

budget_kr = read_number("Budget in whole DKK (0..1000):", 0, 1000);

if (budget_kr == -1) {
return -1;
                }

budget_cent = budget_kr * 100;

build_needs(recipes[recipe_id], needed);

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
    show_instructions(recipes[recipe_id]);

    return 0;
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
show_context(stores, address);
printf("All spices are included, Stock is currently 0\n");
result = run_calculation(items, stores, recipes);

if (result == -1) {
    return 1;
}

return 0;

                }


