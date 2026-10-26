#include "funktioner.h"

/* Færdigt eksempel: en funktion tager tal ind og giver ét tal tilbage.
   Eksempel: behov 150 g og lager 100 g giver 50 g i mangel. -AK */
int manglende_maengde(int behov, int lager)
{
    int mangel = behov - lager;
    if (mangel < 0) {
        return 0;
    }
    return mangel;
}


int price_for_item(int behov, int lager, int pakke, int pris_oere)
{
   int mangel = manglende_maengde(behov, lager);

   if (mangel == 0){
    return 0;
   }

   if (pakke <= 0 || pris_oere <= 0) {
      return -1;
   }

   int antal = 0;
   int købt = 0;
   while (købt < mangel) {
    købt = købt + pakke;
    antal = antal + 1;
   }

    return antal * pris_oere;
}

