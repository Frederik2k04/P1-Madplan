# P1 Madplan - start her

En lille foundation i almindelig HTML og C. I skal selv lave hovedfunktionerne.
Start med at åbne siderne og køre C-programmet. Lav derefter én TODO ad gangen.

## Projektets mål og faste prisrækkefølge — 23. oktober 2026

Brugeren søger fx burger, vælger en konkret opskrift og antal personer og får
et indkøbsestimat for **de tre nærmeste konkrete supermarkeder**, samt prisen
for den tilsvarende varekurv leveret fra **Wolt Market** til brugerens adresse.
Alle filialer, som kan findes, skal registreres på tværs af Netto, føtex,
REMA 1000, 365discount, SuperBrugsen, Kvickly, MENY, SPAR og Lidl.

For hver nødvendig ingrediens/vare bruges denne rækkefølge:

1. **Live pris fra den konkrete butik.**
2. **Senest kendte pris fra den konkrete butik.**
3. **Kendt pris fra samme supermarkedskæde**, tydeligt vist som estimat.
4. **Ukendt pris**, når de øvrige muligheder ikke giver en brugbar pris.

En butik må godt have en blanding af prisgrundlag. En manglende lokalpris skal
føre til næste prioritet; den må ikke udelukke hele butikken eller kæden.
Ukendt er aldrig 0 kr. Vis kendt delsum og antal ukendte varer, når en fuld total
ikke kan beregnes. Lagerstatus vises særskilt. Beregn indkøb i hele pakker og
penge i hele øre, efter at brugerens hjemmelager er trukket fra.

Alle senest kendte produktpriser samles i **én SQLite-fil: `priser.sqlite`**.
Hver pris beholder kæde, konkret butik eller kædeomfang, salgskanal, vare-id,
pakkestørrelse, betingelser og tidspunkt. C skal læse denne fil og udføre
prioriteringen og beregningerne; HTML viser dem. Gruppen bygger selv funktionerne.

Wolt-priser holdes adskilt fra fysiske butikspriser. En præcis leveret total
kræver aktuelle priser og gebyrer for netop adressen, varekurven og eventuelt
Wolt+-medlemskab. En ukendt leveringspris må ikke sættes til 0 kr.

Den detaljerede implementeringsplan og et datasnapshot ligger i Codex-chattens
`outputs/madplan-plan/`. Der er ikke indsat færdig appkode i denne foundation.

## 1. Åbn HTML
Åbn `html/index.html` ved at dobbeltklikke på filen. Brug links til alle fire sider.
Ingen installation, server eller internetforbindelse er nødvendig for HTML.
Siderne er bevidst uden styling, så HTML er let at læse.

## 2. Kør C
Åbn en terminal **i den yderste P1-Madplan-mappe**, hvor denne README ligger.
Med VS Code: åbn denne mappe og vælg Terminal → New Terminal.

Med en C-compiler installeret på Mac/Linux:

```sh
cc -std=c11 -Wall -Wextra -Wpedantic c/main.c c/pris.c -o madplan
./madplan
```

Windows med GCC i terminalens søgesti:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic c/main.c c/pris.c -o madplan.exe
.\madplan.exe
```

Hvis `cc` eller `gcc` ikke findes, skal I først bruge/installere en C-compiler
som i jeres kursusmiljø. HTML kræver kun en browser.
Byg igen, hver gang I ændrer C-koden.

Forventet output nu:

```text
Madplan - foundation med faste testdata
Budget: 60 kr.
Ris: behov 150 g, hjemme 100 g, mangel 50 g.
Risens pris er ikke beregnet endnu. Se TODO i c/pris.c.
```

## 3. Hvad virker allerede?
- Fire HTML-sider med links og tydeligt mærkede eksempeldata.
- Et C-program med faste tal og en færdig funktion, der beregner manglende mængde.
- En ufærdig prisfunktion, som giver -1, indtil I selv laver beregningen.
- Et arbejdsark med tre testvarer og facit i `data/varer.txt`.

HTML og C arbejder hver for sig. Ændring i terminalen ændrer ikke HTML-siderne.
Resultatsiden er et håndskrevet facit, som viser, hvad I senere skal beregne.

## 4. Hvem begynder hvor?
| Person | Fil | Første opgave |
|---|---|---|
| AK | `c/main.c` | Læs og udskriv budget fra terminalen |
| Freddy | `c/pris.c` | Lav `pris_for_vare` ved at følge TODO 1-5 |
| Mert | `html/index.html` | Skriv introduktion og prøv navigationen |
| Peter | `html/opskrift.html` | Gennemgå opskrift og mængder med Freddy |
| Hasibullah | `html/lager.html`, `data/varer.txt` | Tilpas lageroversigt og kontrollér testtallene |

Mert og AK aftaler senere resultatets udseende. Hasibullah prøver denne vejledning
fra en anden computer. Aftal, hvem der retter README, så I ikke retter samtidig.

## 5. Det skal I selv bygge - i denne rækkefølge
1. Freddy laver prisberegningen for én vare. Betal for **hele pakker**.
2. AK læser budget og hjemmelager. Afvis ugyldigt input, fx tekst og negative tal.
3. AK og Freddy tilføjer æg og broccoli, lægger priser sammen og viser restbudget.
   Ved ukendt pris: vis kendt delsum og antal ukendte varer. Penge regnes i hele øre.
4. AK lader C skrive `html/resultat-genereret.html` med `fopen`, `fprintf` og `fclose`.
   Kontrollér filfejl. Brug strukturen fra `html/resultat.html` som eksempel.
   Mert tilføjer et link, når filen findes. Genindlæs browseren efter hver kørsel.
5. Tilslut prisdatabasen og derefter én datakilde ad gangen. Start med én opskrift
   og tre konkrete butikker; udvid derefter til alle ni kæder med prisrækkefølgen ovenfor.

Den første øvelse kræver ingen API-kode eller biblioteker. SQLite og datakilderne
tilsluttes senere. TheMealDB og Madpris var tidligere forslag og er ikke valgte integrationer.
Prisoplysninger fortæller ikke sikkert, hvad der er på butikkens hylder.
I skal selv forbinde opskriftens ingredienser med butikkens varer og pakkestørrelser.

## 6. Sådan læser I startkoden
- `main.c` har programmets start: `main`.
- `pris.c` har funktioner til beregninger. Den har ikke sin egen `main`.
- `funktioner.h` deler funktionernes navne og argumenter mellem C-filerne.
- `#include` gør en header tilgængelig i en C-fil.
- `return` giver funktionens svar tilbage til den, som kaldte den.
- `TODO` er en opgave til jer. Startkoden kan køre, selv om opgaverne mangler.
- `data/varer.txt` er et arbejdsark; programmet læser endnu ikke filen.

For én vare skal behov, lager og pakke have samme enhed: g, ml eller stk.
Funktionen `manglende_maengde` forudsætter ikke-negative mængder.
I skal kontrollere brugerens input, før I kalder beregningerne.

## 7. Prøv jeres egen løsning
Når I har lavet beregningerne, skal disse kontroller passe:

| Kontrol | Facit |
|---|---|
| Ris: behov 150 g, lager 100 g, pakke 1000 g til 1800 øre | 1800 øre |
| Ris: behov 1001 g, lager 0 g, samme pakke og pris | 3600 øre |
| Alle tre varer med lager fra arbejdsarket, budget 60 kr. | 51 kr. indkøb, 9 kr. tilbage |
| Alle nødvendige mængder allerede hjemme | 0 kr. indkøb |
| Samme indkøb og budget 50 kr. | 1 kr. over budget |
| Negativt input, manglende pris eller ugyldig pakke | Tydelig fejl, ingen falsk total |

## 8. GitHub - små opgaver
Hent nyeste main → lav en branch til din opgave → ret din aftalte fil → prøv den →
commit → push → pull request → en anden gennemgår → merge.

Denne foundation er kun oprettet lokalt. Der er ikke lavet commit eller push.
Den indre mappe `P1-Madplan/` er en separat, eksisterende Git-kopi og er bevaret.
Arbejd i den yderste mappe. Undgå at føje den indre mappe til jeres commit.
`madplan` og `madplan.exe` ignoreres: del C-koden, og byg programmet på hver computer.

## Tidligere README-indhold (bevaret)

# P1-Madplan
P1 madplan 
test 1
test 2
mert test
ak testss
freddy cursor test vs
