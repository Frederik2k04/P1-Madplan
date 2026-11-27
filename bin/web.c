#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int load_stock(int stock[])
{
FILE *file;
    int item_id;
    int amount;

    file = fopen("data/stock.txt", "r");

    if (file == NULL) {
        return 1;
    }

    while (fscanf(file, "%d %d", &item_id, &amount) == 2) {
        if (item_id >= 1 && item_id <= MAX_ITEMS) {
            stock[item_id] = amount;
        }
    }

    fclose(file);

    return 1;
            }

int main (void) {
int recipe_id = 0;
int people = 0;
int budget_kr = 0;
int include_spices = 0;
int found;
Item items[MAX_ITEMS + 1] = {0};
Store stores [MAX_STORES + 1] = {0};
Recipe recipes [MAX_RECIPES + 1] = {0};
int needed[MAX_ITEMS + 1] = {0};
int stock[MAX_ITEMS + 1] = {0};
int selected_ids[MAX_ITEMS + 1] = {0};
int budget_cent;


printf("Content-Type: text/html; charset=utf-8\n\n");

    if (getenv("QUERY_STRING") == NULL) {
        printf("<p>No input was received.</p>\n");
        return 0;
            }
found = sscanf(getenv("QUERY_STRING"),"recipe=%d&people=%d&budget=%d&spices=%d",
                   &recipe_id, &people, &budget_kr, &include_spices);
    
    if (found != 4) {
        printf("<p>Please fill in every field.</p>\n");
        return 0;
            }
    if (load_stores(stores) == 0 || load_items(items) == 0 || load_prices(items) == 0) {
        printf("<p>The data files could not be loaded.</p>\n");
        return 0;
            }
    if (load_recipes(recipes) == 0 || load_ingredients(recipes) == 0) {
        printf("<p>The recipe files could not be loaded.</p>\n");
        return 0;
            }
    if (recipe_id < 1 || recipe_id > MAX_RECIPES || recipes[recipe_id].loaded == 0) {
        printf("<p>The recipe does not exist.</p>\n");
        return 0;
            }
    if (people < 1|| people > 100) {
        printf("<p>Number of people must be between 1 and 100</p>\n");
        return 0;
            } 
    if (budget_kr < 0 || budget_kr > 10000) {
        printf("<p>The budget must be between 0 and 10.000 DKK.</p>\n");
        return 0;
            }

for (int item_id = 1; item_id <= MAX_ITEMS; item_id = item_id + 1) {
    selected_ids[item_id] = item_id;
            }
build_needs(recipes[recipe_id], items, include_spices, selected_ids, needed);

for (int item_id = 1; item_id <=MAX_ITEMS; item_id = item_id + 1) {
    needed[item_id] = (needed[item_id] * people + 1) / 2;
            }
budget_cent = budget_kr * 100;
load_stock(stock);

printf("<h2>%s - %d people</h2>\n", recipes[recipe_id].name, people);

printf("<p>Budget: %d,%02d DKK</p>\n", budget_cent / 100, budget_cent % 100);

printf("<table>\n");
printf("<tr><th>Store</th><th>Total</th><th>Budget</th></tr>\n");


for (int store_id = 1; store_id <= MAX_STORES; store_id = store_id + 1) {
int total;
total = calculate_store(items, needed, stock, store_id);

    if (total == -1) {
        printf("<tr><td>%s</td><td>Missing price</td><td>-</td></tr>\n", stores[store_id].name);
    } 
    else if (total <= budget_cent) {
        printf("<tr><td>%s</td><td>%d,%02d DKK</td><td>Within budget</td></tr>\n",
                   stores[store_id].name, total / 100, total % 100);
        } 
                   else {
        printf("<tr><td>%s</td><td>%d,%02d DKK</td><td>Over budget</td></tr>\n",
                   stores[store_id].name, total / 100, total % 100);

            }
            }
    printf("</table>\n");


    return 0;

        }
