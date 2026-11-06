#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* This header declares the functions implemented in price.c.
   Use the same unit for all quantities of one item. Prices are integer ore. */
int missing_amount(int need, int stock);
int price_for_item(int need, int stock, int item, int price_cent);
int read_line(char text[], int capacity);

#endif


