#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/* En header (.h) fortæller andre C-filer, hvilke funktioner der findes.
   Selve funktionerne står i pris.c. Alle mængder for én vare skal
   bruge samme enhed. Alle priser er i hele øre. */
int missing_amount(int need, int stock);
int price_for_item(int need, int stock, int item, int price_cent);

#endif
