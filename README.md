# Meal planner

P1 project, 1st semester. A small C program for the terminal. You pick a recipe and a budget, and it tells you what the groceries cost in 3 stores.

## Run it

You need CMake and a C compiler. Run this in the terminal from this folder (the one with `CMakeLists.txt` in it). It builds the program and starts it:

```
cmake -S . -B build; cmake --build build --target run
```

It has to be run from this folder, or the program cant find the data files. On Windows the program opens in its own window.

## Web version

Run this in the terminal from the project folder:

```
cmake -S . -B build; cmake --build build --target web
```

Then open `http://localhost:8000/frontend/html/resultat.html` in the browser. Close the terminal (or press Ctrl+C) to stop the server.

Input is limited in this version: there is no home storage in the calculation yet, and no replacements.

## How to use it

The program asks for:

- recipe number (1-5)
- how many people are eating (1-100)
- budget in DKK (0-10000)
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

## Known problems

- only tested on Mac
- if a data file is wrong it just says which line and stops
