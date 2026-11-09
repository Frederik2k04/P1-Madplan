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
