#include <stdio.h>
#include "funktioner.h"

/* AK: main er programmets start. Byg og kør fra projektets hovedmappe.
   Første version bruger faste testtal. Ingen data hentes fra nettet. */
int main(void)
{
    int budget_oere = 6000;
    int behov_ris = 150;
    int lager_ris = 100;
    int mangel = manglende_maengde(behov_ris, lager_ris);
    int pris = pris_for_vare(behov_ris, lager_ris, 1000, 1800);

    printf("Madplan - foundation med faste testdata\n");
    printf("Budget: %d kr.\n", budget_oere / 100);
    printf("Ris: behov %d g, hjemme %d g, mangel %d g.\n",
           behov_ris, lager_ris, mangel);

    if (pris < 0) {
        printf("Risens pris er ikke beregnet endnu. Se TODO i c/pris.c.\n");
    } else {
        printf("Indkoeb af ris: %d,%02d kr.\n", pris / 100, pris % 100);
    }

    /* AK - lav én opgave ad gangen:
       TODO 1: Læs budget fra terminalen og udskriv det igen.
               Kontrollér input; afvis tekst og negative tal.
       TODO 2: Læs hjemmelager for ris, æg og broccoli.
       TODO 3: Kald pris_for_vare for hver vare med testtallene fra data/varer.txt.
       TODO 4: Vis kun total og restbudget, hvis alle priser er gyldige.
               Vis også, hvis budgettet overskrides.
       TODO 5 (senere): Skriv resultatet til HTML. Se README. */
    return 0;
}
