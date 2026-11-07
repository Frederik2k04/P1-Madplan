#include "functions.h"
#include <limits.h>


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

/* Price in cents (ore) for one item.
   0 = nothing to buy. -1 = invalid numbers.
   Check: (150, 100, 1000, 1800) gives 1800. */
int price_for_item(int need, int stock, int item, int price_cent)
{
    if (need < 0 || stock < 0) {
        return -1;
    }


    int missing = missing_amount(need, stock);

    if (missing == 0) {
        return 0;
    }

    if (item <= 0 || price_cent <= 0) {
        return -1;
    }

    int packages = count_packages(missing, item);
    if (packages > INT_MAX / price_cent) {
        return -1;
    }
    int total_cent =packages * price_cent;
    return total_cent;
}




    int count_packages(int missing, int package_amount){
    if (missing < 0 || package_amount <= 0)
    {
        return -1;
    }
    int packages = missing / package_amount;
    int remainder = missing %
    package_amount;
    if (remainder > 0)
    {
        packages = packages + 1;

    }
return packages;

    }




