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
