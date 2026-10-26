#include <stdio.h>
#include "funktioner.h"
#include "pris.c"

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
    int budget_oere = budget_kr * 100;

    int need_rice = 150;

    int need_egg = 2;
    int need_broccoli = 200;

    int storage_rice;
    printf("rice home (gram): ");
    if (scanf("%d", &storage_rice) !=1 ||
     storage_rice < 0 || storage_rice > 100000) {

    printf("Write a whole number from 0 to 10.000.\n");
            return 1;
     }

      int storage_egg;
    printf("egg home (stk): ");
    if (scanf("%d", &storage_egg) !=1 ||
     storage_egg < 0 || storage_egg > 100000) {

    printf("Write a whole number from 0 to 10.000.\n");
            return 1;
     }

      int storage_broccoli;
    printf("broccoli home (gram): ");
    if (scanf("%d", &storage_broccoli) !=1 ||
     storage_broccoli < 0 || storage_broccoli > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }


    int req = manglende_maengde(need_rice, storage_rice);
    int req_egg = manglende_maengde(need_egg, storage_egg);
    int req_broccoli = manglende_maengde(need_broccoli, storage_broccoli);


    int price = price_for_item(need_rice, storage_rice, 1000, 1800);

    printf("Madplan - foundation with clear testdata\n");
    printf("Budget: %d kr.\n", budget_oere / 100);
    
    if(req == 0) {
        printf("Rice: need %d g, home %d g. You have enough.\n",
           need_rice, storage_rice);
    } else {
        printf("Rice: need %d g, home %d g, missing %d g. \n", 
            need_rice, storage_rice, req);
    }

    if(req == 0) {
        printf("egg: need %d stk, home %d stk. you have enough.\n",
           need_egg, storage_egg);
    } else {
        printf("egg: need %d stk, home %d stk, missing %d stk. \n", 
            need_egg, storage_egg, req_egg);
    }

    if(req_broccoli == 0) {
        printf("Broccoli: need %d g, home %d g. You have enough.\n",
           need_broccoli, storage_broccoli);
    } else {
        printf("Broccoli: Need %d g, home %d g, missing %d g. \n", 
            need_broccoli, storage_broccoli, req_broccoli);
    }

    

    if (price < 0) {
        printf("price is not calculated yet. Se TODO i c/pris.c.\n");
    } else {
        printf("buy ris: %d,%02d kr.\n", price / 100, price % 100);
    }

    /* AK - lav én opgave ad gangen:
       
       
       TODO 3: Kald pris_for_vare for hver vare med testtallene fra data/varer.txt.
       TODO 4: Vis kun total og restbudget, hvis alle priser er gyldige.
               Vis også, hvis budgettet overskrides.
       TODO 5 (senere): Skriv resultatet til HTML. Se README. */
    return 0;
}
