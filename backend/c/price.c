#include "functions.h"

/* Missing amount: need minus stock, never below 0.
   Example: need 150 g, stock 100 g gives 50 g missing. -AK */
int missing_amount(int need, int stock)
{
    int missing = need - stock;
    if (missing < 0) {
        return 0;
    }
    return missing;
}

/* Price in cents (øre) for one item.
   0 = nothing to buy. -1 = invalid numbers.
   Check: (150, 100, 1000, 1800) gives 1800. */
int price_for_item(int need, int stock, int item, int price_cent)
{
    int missing = missing_amount(need, stock);

    if (missing == 0) {
        return 0;
    }

    if (item <= 0 || price_cent <= 0) {
        return -1;
    }

    int amount = 0;
    int bought = 0;
    while (bought < missing) {
        bought = bought + item;
        amount = amount + 1;
    }

    return amount * price_cent;
}