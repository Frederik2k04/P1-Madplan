#!/bin/sh
# Dobbeltklik for at bygge og starte madplanen.
# Filen ligger i mappen "start" inde i projektmappen, så projektet er mappen over.

here=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
project=$(dirname "$here")

if [ ! -f "$project/backend/c/main.c" ]; then
    echo "Kunne ikke finde projektet (backend/c/main.c) i: $project"
    echo "Mappen 'start' skal ligge direkte i projektmappen."
    printf 'Tryk Enter for at lukke.'; read -r _
    exit 1
fi

if ! command -v cc >/dev/null 2>&1; then
    echo "Der er ingen C-compiler. Skriv 'xcode-select --install' i Terminal, og prøv igen."
    printf 'Tryk Enter for at lukke.'; read -r _
    exit 1
fi

tmp=$(mktemp -d)
cd "$project" || exit 1
echo "Projekt: $project"

if cc -std=c11 -Wall -Wextra -Wpedantic -Werror \
    backend/c/main.c backend/c/catalog.c backend/c/recipes.c backend/c/price.c backend/c/terminal.c \
    -o "$tmp/mealplan"; then
    "$tmp/mealplan"
else
    echo
    echo "Programmet kunne ikke bygges. Fejlen står ovenfor."
fi

rm -f "$tmp/mealplan"
rmdir "$tmp"
printf '\nTryk Enter for at lukke.'; read -r _
