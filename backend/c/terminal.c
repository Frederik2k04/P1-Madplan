#include "functions.h"
#include <stdio.h>
#include <string.h>

int read_line(char text[], int capacity)
{
    if (fgets(text, capacity, stdin) == NULL) {
        if (ferror(stdin)) {
            fprintf(stderr, "Cannot read terminal input.\n");
        }
        return 0;
    }
    int length = (int)strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
        length = length - 1;
    } else {
        int character = getchar();
        if (character != EOF) {
            while (character != '\n' && character != EOF) {
                character = getchar();
            }
            return -1;
        }
    }
    if (length > 0 && text[length - 1] == '\r') {
        text[length - 1] = '\0';
    }
    return 1;
}
