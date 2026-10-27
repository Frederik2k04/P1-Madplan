#include "functions.h"

/* Færdigt eksempel: en funktion tager tal ind og giver ét tal tilbage.
int manglende_maengde(int behov, int lager)
{
    int mangel = behov - lager;
    if (mangel < 0) {

{
    int missing = need - stock;
    if (missing < 0) {
        return 0;
    }
    return missing;
}

/* FREDDY: Denne funktion er jeres opgave.
   -1 betyder, at prisen endnu ikke er beregnet. Det betyder ikke gratis.
   TODO 1: Find manglen ved at kalde manglende_maengde.
   TODO 2: Returnér 0, hvis der ikke mangler noget.
   TODO 3: Returnér -1 ved ugyldige tal, fx pakke <= 0.
   TODO 4: Tæl hele pakker, indtil manglen er dækket.
   TODO 5: Returnér antal pakker gange pris_oere.
   Facit: (150, 100, 1000, 1800) skal give 1800 øre.
   Prøv også mangel på 1001 g: det kræver to pakker på 1000 g. */
int price_for_item(int behov, int lager, int pakke, int pris_oere)

{
   int missing = missing_amount(need, stock);

   if (missing == 0){
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

