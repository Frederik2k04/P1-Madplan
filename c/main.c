#include <stdio.h>
#include "funktioner.h"
#include "pris.c"

/* Programmets start.
   Første version bruger faste testtal. Ingen data hentes fra nettet. */

int main(void)
{
    int budget_kr;
    printf("Budget i hele kroner:");
    if (scanf("%d", &budget_kr) !=1 ||
    budget_kr < 0 || budget_kr > 10000) {
        printf( "skriv et helt tal fra 0 til 10.000.\n") ;
            return 1;
        }
    int budget_oere = budget_kr * 100;

    int behov_ris = 150;

    int behov_aeg = 2;
    int behov_broccoli = 200;

    int lager_ris;
    printf("ris hjemme (gram): ");
    if (scanf("%d", &lager_ris) !=1 ||
     lager_ris < 0 || lager_ris > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }

      int lager_aeg;
    printf("æg hjemme (gram): ");
    if (scanf("%d", &lager_aeg) !=1 ||
     lager_aeg < 0 || lager_aeg > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }

      int lager_broccoli;
    printf("broccoli hjemme (gram): ");
    if (scanf("%d", &lager_broccoli) !=1 ||
     lager_broccoli < 0 || lager_broccoli > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }


    int mangel = manglende_maengde(behov_ris, lager_ris);
    int mangel_aeg = manglende_maengde(behov_aeg, lager_aeg);
    int mangel_broccoli = manglende_maengde(behov_broccoli, lager_broccoli);


    int pris = pris_for_vare(behov_ris, lager_ris, 1000, 1800);

    printf("Madplan - foundation med faste testdata\n");
    printf("Budget: %d kr.\n", budget_oere / 100);
    
    if(mangel == 0) {
        printf("Ris: behov %d g, hjemme %d g. Du har nok.\n",
           behov_ris, lager_ris);
    } else {
        printf("Ris: Behov %d g, hjemme %d g, mangel %d g. \n", 
            behov_ris, lager_ris, mangel);
    }

    if(mangel == 0) {
        printf("Æg: behov %d g, hjemme %d g. Du har nok.\n",
           behov_aeg, lager_aeg);
    } else {
        printf("Æg: Behov %d stk, hjemme %d stk, mangel %d stk. \n", 
            behov_aeg, lager_aeg, mangel);
    }

    if(mangel == 0) {
        printf("Broccoli: behov %d g, hjemme %d g. Du har nok.\n",
           behov_broccoli, lager_broccoli);
    } else {
        printf("Broccoli: Behov %d g, hjemme %d g, mangel %d g. \n", 
            behov_broccoli, lager_broccoli, mangel);
    }

    

    if (pris < 0) {
        printf("Risens pris er ikke beregnet endnu. Se TODO i c/pris.c.\n");
    } else {
        printf("Indkoeb af ris: %d,%02d kr.\n", pris / 100, pris % 100);
    }

    /* AK - lav én opgave ad gangen:
       
       TODO 2: Læs hjemmelager for ris, æg og broccoli.
       TODO 3: Kald pris_for_vare for hver vare med testtallene fra data/varer.txt.
       TODO 4: Vis kun total og restbudget, hvis alle priser er gyldige.
               Vis også, hvis budgettet overskrides.
       TODO 5 (senere): Skriv resultatet til HTML. Se README. */
    return 0;
}
