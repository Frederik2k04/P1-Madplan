#include "functions.h"
#include <stdio.h>


int main(void)
{
    Store stores[MAX_STORES + 1] = {0};
    if (load_stores(stores) == 0) {
        return 1;
                }

    char address [160];
    if (read_address(address) == 0) {
        return 1;
                }
    show_context(stores, address);
                
    int budget_kr;
    int budget_cent;
    int need_rice = 150;
    int need_egg = 2;
    int need_broccoli = 200;
    int stock_rice; 
    int stock_egg;
    int stock_broccoli;
    int missing_rice;
    int missing_egg;
    int missing_broccoli;
    int price_rice;
    int price_egg;
    int price_broccoli;
    int total_cent;

    budget_kr = read_number("Budget in whole DKK (0..1000):", 0, 1000);

    if (budget_kr == -1) {
        return 1;
    }

    budget_cent = budget_kr * 100;
    stock_rice = read_number("Rice at home (g, 0..5000):", 0, 5000);

    if (stock_rice == -1) {
        return 1;
    }

    stock_egg = read_number("Eggs at home (pcs, 0..5000):", 0, 5000);

    if (stock_egg == -1) {
        return 1;
    }

    stock_broccoli = read_number("Broccoli at home (g, 0..5000):", 0, 5000);

    if (stock_broccoli == -1) {
        return 1;
    }

    missing_rice = missing_amount(need_rice, stock_rice);
    missing_egg = missing_amount(need_egg, stock_egg);
    missing_broccoli = missing_amount(need_broccoli, stock_broccoli);

    price_rice = price_for_item(need_rice, stock_rice, 1000, 1800);
    price_egg = price_for_item(need_egg, stock_egg, 6, 1800);
    price_broccoli = price_for_item(need_broccoli, stock_broccoli, 500, 1500);

    printf("\nRice: need %d g, home %d g, missing %d g\n",
           need_rice, stock_rice, missing_rice);
    printf("Eggs: need %d pcs, home %d pcs, missing %d pcs\n",
           need_egg, stock_egg, missing_egg);
    printf("Broccoli: need %d g, home %d g, missing %d g\n",
           need_broccoli, stock_broccoli, missing_broccoli);

    printf("Rice purchase: %d,%02d DKK\n", price_rice / 100, price_rice % 100);
    printf("Egg purchase: %d,%02d DKK\n", price_egg / 100, price_egg % 100);
    printf("Broccoli purchase: %d,%02d DKK\n", price_broccoli / 100, price_broccoli % 100);

    total_cent = price_rice + price_egg + price_broccoli;
    printf("Total: %d,%02d DKK\n", total_cent / 100, total_cent % 100);

    if (total_cent <= budget_cent) {
        int left;

        left = budget_cent - total_cent;
        printf("Left: %d,%02d DKK\n", left / 100, left % 100);
    } else {
        int over;

        over = total_cent - budget_cent;
        printf("Over budget: %d,%02d DKK\n", over / 100, over % 100);
    }

    return 0;
}
