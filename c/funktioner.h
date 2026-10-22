#ifndef FUNKTIONER_H
#define FUNKTIONER_H

/* En header (.h) fortæller andre C-filer, hvilke funktioner der findes.
   Selve funktionerne står i pris.c. Alle mængder for én vare skal
   bruge samme enhed. Alle priser er i hele øre. */
int manglende_maengde(int behov, int lager);
int pris_for_vare(int behov, int lager, int pakke, int pris_oere);

#endif
