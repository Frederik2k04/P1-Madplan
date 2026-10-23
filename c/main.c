#include <stdio.h>
#include "funktioner.h"


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

    int lager_ris;
    printf("ris hjemme (gram): ");
    if (scanf("%d", &lager_ris) !=1 ||
     lager_ris < 0 || lager_ris > 100000) {

    printf("skriv et helt tal fra 0 til 10.0000.\n");
            return 1;
     }

    int mangel = manglende_maengde(behov_ris, lager_ris);
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
