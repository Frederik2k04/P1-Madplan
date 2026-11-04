# Meal planner · beginner C project

The original program is developed in this project folder. It currently contains
`backend/c/main.c`, `price.c` and `functions.h`. The learning guide starts by
explaining those files and then develops the program one function at a time.

## Open the learning guide

Open [the learning guide](<../Produkt test/p1 madplan test/laeseguider/index.html>).
Choose your person and either **Guide 1 · Learn and write it yourself** or
**Guide 2 · Build with code and explanations**.

The guide has a **Use my project path (Freddy)** button and a custom-folder option.
Both update the displayed locations and the commands copied to Terminal. Guide 2
has a fixed expandable full-code drawer on pages that change C code.

## Three input files

| File | Contents |
|---|---|
| `backend/data/items.txt` | Stores 1–3, items 1–23, 69 package prices and two substitutions. |
| `backend/data/address.txt` | One case address. |
| `backend/data/recipes.txt` | Recipes 1–5, each serving two people, with ingredients and cooking steps. |

Each register starts at 1. An ID is not an array index: item ID 1 normally occupies
index 0. Prices are integer ore. Quantities use g, ml or pcs.

```
PRICE;item_id;store_id;product;package_amount;package_price_ore
```

Price rows have exactly six fields. Dates and sources are documented only in the
guide. The inherited data is 66 project prices and three Netto advertisement
prices; it does not establish the cheapest local shelf-price basket.

The starting program does not yet read these files. Follow the guide to build
that functionality in this same project. The separate step folders contain
AI-authored teaching references, not automatically submitted student code.

## Run the original starting program

Run from this project root:

```sh
mkdir -p backend/c/output &&
cc -std=c11 -Wall -Wextra -Wpedantic -Werror backend/c/main.c backend/c/price.c -o backend/c/output/mealplan &&
printf '60\n100\n1\n0\n' | ./backend/c/output/mealplan
```

Expected total: 51 DKK; remaining budget: 9 DKK. Once you start adding functions,
use the command shown in the current lesson instead of this starting command.

## Working together

Person 1 owns main.c, price.c, catalog.c and the shared functions.h. Person 2 owns
terminal.c and recipes.c. Only Person 1 edits the shared header. Obtain the listed
dependencies before integration. All submitted code must meet your supervisor’s
requirements for authorship, understanding and independent explanation.

The older frontend and input material is historical and is not required by this
reduced terminal program. No network, SQL or browser integration is required.
