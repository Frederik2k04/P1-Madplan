#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Item items[MAX_ITEMS + 1] = {0};
    int stock[MAX_ITEMS + 1] = {0};
    char *query;
    int position;
    int used;
    int item_id;
    int amount;
    FILE *file;

    printf("Content-Type: text/html; charset=utf-8\n\n");

    if (load_items(items) == 0) {
        printf("<p>items.txt could not be loaded.</p>\n");
        return 0;
    }

    query = getenv("QUERY_STRING");
    position = 0;

    while (query != NULL && sscanf(query + position, "%d=%d%n", &item_id, &amount, &used) == 2) {
        if (item_id >= 1 && item_id <= MAX_ITEMS && amount >= 0 && amount <= 100000) {
            stock[item_id] = amount;
        }

        position = position + used;

        if (query[position] == '&') {
            position = position + 1;
        }
    }

    file = fopen("data/stock.txt", "w");

    if (file == NULL) {
        printf("<p>The home storage could not be saved.</p>\n");
        return 0;
    }

    for (int id = 1; id <= MAX_ITEMS; id = id + 1) {
        if (stock[id] > 0) {
            fprintf(file, "%d %d\n", id, stock[id]);
        }
    }

    fclose(file);

    printf("<h2>Saved home storage</h2>\n<ul>\n");

    for (int id = 1; id <= MAX_ITEMS; id = id + 1) {
        if (stock[id] > 0) {
            printf("<li>%s: %d %s</li>\n", items[id].name, stock[id], items[id].unit);
        }
    }

    printf("</ul>\n");

    return 0;
}
