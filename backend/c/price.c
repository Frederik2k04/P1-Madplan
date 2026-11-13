#include "functions.h"
#include <stdio.h>

int missing_amount(int need, int stock)
{
    int missing;

    missing = need - stock;

    if (missing < 0) {
        missing = 0;
    }

    return missing;
}

int count_packages(int missing, int package_amount)
{
    int packages;
    int remainder;

    packages = missing / package_amount;
    remainder = missing % package_amount;

    if (remainder > 0) {
        packages = packages + 1;
    }

    return packages;
}

int price_for_item(int need, int stock, int package_amount, int package_price)
{
    int missing;
    int packages;
    int total_cent;

    missing = missing_amount(need, stock);
    packages = count_packages(missing, package_amount);
    total_cent = packages * package_price;

    return total_cent;
            }

int calculate_store(Item items[], int needed[], int stock[], int store_id)
{
    int total_cent;
    total_cent = 0;

for (int item_id = 1; item_id <= MAX_ITEMS; item_id = item_id + 1) {
    int missing;
    int package_amount;
    int package_price;
    int item_total;

    missing = missing_amount(needed[item_id], stock[item_id]);

    if (missing > 0) {
            package_amount = items[item_id].package_amount[store_id];
            package_price = items[item_id].price_cent[store_id];

    if (package_amount == 0) {
        return -1;
                }

    item_total = 
    price_for_item(needed[item_id], stock [item_id], package_amount, package_price);
    total_cent = total_cent + item_total;
                }
                }
    return total_cent;

                }

void show_comparison(Store stores[], int totals[], int budget_cent)
{
    int lowest;

    lowest = -1;

    for (int store_id = 1; store_id <= MAX_STORES; store_id = store_id + 1) {
        if (totals[store_id] >= 0) {
            if (lowest == -1) {
                lowest = totals[store_id];
                }

            if (totals[store_id] < lowest) {
                lowest = totals[store_id];
                }
        }
    }

    printf("\nYour entire basket\n");
    printf("Budget: %d,%02d DKK\n", budget_cent / 100, budget_cent % 100);

    for (int store_id = 1; store_id <= MAX_STORES; store_id = store_id + 1) {
        int total;

        total = totals[store_id];
        printf("%d. %s\n", store_id, stores[store_id].name);

    if (total == -1) {
    printf("\033[31mERROR, Required package price missing\033[0m\n");
                    } 
    else {
            int difference;

    printf("   Total: %d,%02d DKK\n", total / 100, total % 100);

    if (total == lowest) {
    printf("   Lowest complete total.\n");
                    }

    if (total <= budget_cent) {
            difference = budget_cent - total;
    printf("   Left in budget: %d,%02d DKK\n", difference / 100, difference % 100);
                    }   
    else {
                difference = total - budget_cent;
                printf("   Over budget: %d,%02d DKK\n", difference / 100, difference % 100);
                }
                }
                }
                }


void show_receipt(Store store, Item items[], int needed[], int stock[], int store_id) {

int total_cent;
total_cent = 0;
printf("\033[1m\nSHOPPING LISTE:\033[0m\n%s\n%s\n", store.name, store.address);

for (int item_id =1 ; item_id <= MAX_ITEMS; item_id = item_id + 1) {
if (needed[item_id] > 0) {
int missing;
missing = missing_amount (needed[item_id], stock[item_id]);
    printf("%s: need %d, home %d, missing %d %s\n", items[item_id].name, needed[item_id], stock[item_id], missing, items[item_id].unit);

if (missing > 0) {
int package_amount;
int package_price;
int packages;
int item_total;

package_amount = items[item_id].package_amount[store_id];
package_price = items[item_id].price_cent[store_id];
packages = count_packages(missing, package_amount);
item_total = packages * package_price;
total_cent = total_cent + item_total;

    printf("You need to buy %d package(s) of %d %s\n", packages, package_amount, items[item_id].unit);
    printf("Needed package %d,%02d DKK. which is %d,%02d DKK\n", package_price/100, package_price %100, item_total/100, item_total%100);

                } 
else {
printf("All clear!\n");

                }
                }
                }               
printf("Your Shopping Total; %d,%02d DKK\n", total_cent/100, total_cent%100);
                }

