# Meal planner

P1 project, 1st semester. A small C program for the terminal. You pick a recipe and a budget, and it tells you what the groceries cost in 3 stores.

## Run it

Double-click `start/Start.command` on a Mac.

Or run this in the terminal from this folder (the one with `backend` in it):

```
mkdir -p backend/c/output && cc -std=c11 -Wall -Wextra -Wpedantic -Werror backend/c/main.c backend/c/catalog.c backend/c/recipes.c backend/c/price.c backend/c/terminal.c -o backend/c/output/mealplan && ./backend/c/output/mealplan
```

It has to be run from this folder, or it cant find the data files.

## How to use it

The program asks for:

- recipe number (1-5)
- how many people are eating (1-100)
- budget in DKK (0-1000)
- if you need to buy spices (1 = yes, 0 = no)
- how much of each item you already have at home
- store number (1-3)

Type 0 to quit. If a store is missing a price you cant choose it.

Then it prints the shopping list and the steps for the recipe.

## Files

All in `backend/c/`:

- `main.c` - main
- `catalog.c` - loads stores, items and prices
- `price.c` - calculates prices, shows the comparison and the shopping list
- `recipes.c` - loads and shows the recipes
- `terminal.c` - reading input and choosing recipe/store
- `functions.h` - declarations and structs

## Data

The data is in text files in `backend/data/` (stores, items, prices, recipes, ingredients, instructions, replacements and address). The prices are made up by us, they are not real shelf prices. Prices are in øre.

## Not done

- swapping items (the code is written but not connected yet)

## Known problems

- budget max is 1000
- only tested on Mac
- if a data file is wrong it just says which line and stops
