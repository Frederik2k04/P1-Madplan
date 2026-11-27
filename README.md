# Meal planner

P1 project, 1st semester. A small C program for the terminal. You pick a recipe and a budget, and it tells you what the groceries cost in 3 stores.

## Run it

You need CMake and a C compiler. Run this in the terminal from this folder (the one with `CMakeLists.txt` in it). It builds the program and starts it:

```
cmake -S . -B build; cmake --build build --target run
```

It has to be run from this folder, or the program cant find the data files. It is the same on Mac and Windows.

## Web version

Run this in the terminal from the project folder:

```
cmake -S . -B build; cmake --build build --target web
```

Then open `http://localhost:8000/web/index.html` in the browser. Close the terminal (or press Ctrl+C) to stop the server. The web version needs Python 3.0 to 3.14.

Input is limited in this version: there is no home storage in the calculation yet, and no replacements.

## How to use it

The program asks for:

- recipe number (1-5)
- how many people are eating (1-100)
- budget in DKK (0-10000)
- if you need to buy spices (1 = yes, 0 = no)
- how much of each item you already have at home
- store number (1-3)

Type 0 to quit. If you type something that is not a valid answer, it just asks again. If a store is missing a price you cant choose it.

Then it prints the shopping list and the steps for the recipe.

## Files

The folders are set up like the CMake examples from the course:

- `bin/` - the programs (the ones with a `main`)
  - `main.c` - the terminal program
  - `web.c` - calculates the result for the web version
  - `stock.c` - saves the home storage for the web version
- `lib/` - the code the programs share
  - `catalog.c` - loads stores, items and prices
  - `price.c` - calculates prices, shows the comparison and the shopping list
  - `recipes.c` - loads and shows the recipes
  - `terminal.c` - reading input and choosing recipe/store
  - `include/functions.h` - declarations and structs
- `data/` - the text files the program reads
- `web/` - the pages for the web version

## Data

The data is in text files in `data/` (stores, items, prices, recipes, ingredients, instructions, replacements and address). The prices are made up by us, they are not real shelf prices. Prices are in øre.

## Known problems

- only tested on Mac
- if a data file is wrong it just says which line and stops
