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

int read_number(const char prompt[], int minimum, int maximum, int *number)
{
    char text[80];
    while (1) {
        printf("%s", prompt);
        fflush(stdout);
        int status = read_line(text, (int)sizeof text);
        if (status == 0) {
            printf("\nInput ended. Goodbye.\n");
            return 0;
        }
        if (status == 1) {
            if (parse_number(text, minimum, maximum, number)) {
                return 1;
            }
        }
        printf("Enter a whole number from %d to %d.\n", minimum, maximum);
    }
}
