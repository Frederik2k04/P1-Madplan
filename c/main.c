#include <stdio.h>
#include "functions.h"
#include "price.c"

/* Programmets start.
   Første version bruger faste testtal. Ingen data hentes fra nettet. */

int main(void)
{
    int budget_kr;
    printf("Budget in whole kroner:");
    if (scanf("%d", &budget_kr) !=1 ||
    budget_kr < 0 || budget_kr > 10000) {
        printf( "Write a whole number from 0 to 10.000.\n") ;
            return 1;
        }
    int budget_cent = budget_kr * 100;

    int need_rice = 150;

    int need_egg = 2;
    int need_broccoli = 200;

    int stock_rice;
    printf("rice home (gram): ");
    if (scanf("%d", &stock_rice) !=1 ||
     stock_rice < 0 || stock_rice > 100000) {

    printf("Write a whole number from 0 to 10.000.\n");
            return 1;
     }

      int stock_egg;
    printf("egg home (stk): ");
    if (scanf("%d", &stock_egg) !=1 ||
     stock_egg < 0 || stock_egg > 100000) {

    printf("Write a whole number from 0 to 10.000.\n");
            return 1;
     }

      int stock_broccoli;
    printf("broccoli home (gram): ");
    if (scanf("%d", &stock_broccoli) !=1 ||
     stock_broccoli < 0 || stock_broccoli > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }


    int req = missing_amount(need_rice, stock_rice);
    int req_egg = missing_amount(need_egg, stock_egg);
    int req_broccoli = missing_amount(need_broccoli, stock_broccoli);


    int price = price_for_item(need_rice, stock_rice, 1000, 1800);
    int price_egg = price_for_item(need_egg, stock_egg, 6, 1800);
    int price_broccoli = price_for_item(need_broccoli, stock_broccoli, 500, 1500);

    printf("foodplan - foundation with clear testdata\n");
    printf("Budget: %d kr.\n", budget_cent / 100);
    
    if(req == 0) {
        printf("Rice: need %d g, home %d g. You have enough.\n",
           need_rice, stock_rice);
    } else {
        printf("Rice: need %d g, home %d g, missing %d g. \n", 
            need_rice, stock_rice, req);
    }

    if(req == 0) {
        printf("egg: need %d stk, home %d stk. you have enough.\n",
           need_egg, stock_egg);
    } else {
        printf("egg: need %d stk, home %d stk, missing %d stk. \n", 
            need_egg, stock_egg, req_egg);
    }

    if(req_broccoli == 0) {
        printf("Broccoli: need %d g, home %d g. You have enough.\n",
           need_broccoli, stock_broccoli);
    } else {
        printf("Broccoli: Need %d g, home %d g, missing %d g. \n", 
            need_broccoli, stock_broccoli, req_broccoli);
    }

    

    if (price < 0) {
        printf("price is not calculated yet. Se TODO i c/pris.c.\n");
    } else {
        printf("buy rice: %d,%02d kr.\n", price / 100, price % 100);

    }

    (price_egg < 0) {
        printf("price is not calculated yet. Se TODO i c/pris.c.\n");
    } else {
        printf("buy Egg: %d,%02d kr.\n", price_egg / 100, price % 100);
    }

    (price_broccoli < 0) {
        printf("price is not calculated yet. Se TODO i c/pris.c.\n");
    } else {
        printf("buy Broccoli: %d,%02d kr.\n", price_broccoli / 100, price % 100);
    }

    /* AK - lav én opgave ad gangen:
       
       
       TODO 3: Kald pris_for_vare for hver vare med testtallene fra data/varer.txt.
       TODO 4: Vis kun total og restbudget, hvis alle priser er gyldige.
               Vis også, hvis budgettet overskrides.
       TODO 5 (senere): Skriv resultatet til HTML. Se README. */
    return 0;
}
