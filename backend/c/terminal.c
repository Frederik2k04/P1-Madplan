#include "functions.h"
#include <stdio.h>

int read_number(char prompt[], int minimum, int maximum)
{
    int number;
    char ending;
    int values_read;

    printf("%s\n", prompt);
    values_read = scanf("%d%c", &number, &ending);

    if (values_read != 2) {
        printf("Enter one whole number. Calculation stopped.\n");
        return -1;
    }

    if (ending != '\n') {
        printf("Press Enter directly after the number. Calculation stopped.\n");
        return -1;
    }

    if (number < minimum) {
        printf("The minimum is %d. Calculation stopped.\n", minimum);
        return -1;
    }

    if (number > maximum) {
        printf("The maximum is %d. Calculation stopped.\n", maximum);
        return -1;
    }

    return number;
}


int read_text(FILE *file, char text[], int capacity)
{
    char letter;
    int length = 0;
    int result;

    result = fscanf(file, " %c", &letter);

    while (result == 1 && letter != '\n' && length < capacity - 1) {
        text[length] = letter;
        length = length + 1;
        result = fscanf(file, "%c", &letter);
    }

    text[length] = '\0';

    if (length == 0) {
        return 0;
    }

    if (result == 1 && letter != '\n') {
        return 0;
    }

    return 1;
}

int read_address(char address[])
{
    FILE *file;
    int text_ok;

    file = fopen("backend/data/address.txt", "r");

    if (file == NULL) {
        printf("Cannot open backend/data/address.txt.\n");
        return 0;
    }

    text_ok = read_text(file, address, 160);
    fclose(file);

    if (text_ok == 0) {
        printf("Write the case address on the first line of address.txt.\n");
        return 0;
    }

    return 1;
}
