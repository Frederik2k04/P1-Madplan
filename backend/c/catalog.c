#include "functions.h"


    int parse_number(const char text[], int minimum, int maximum, int *number)

                {
    int value = 0;
    int position = 0;
        if (text [0] == '\0') {
            return 0;
                }

while (text[position] !='\0') {
if (text[position] < '0' || text[position] > '9') {
            return 0;
                }
int digit = text[position] - '0';
/* This part checks before multiplying, so even very long numbers cannot overflow. -AK */

if (value > maximum / 10) {
            return 0;
                }

if (value == maximum/10) {
    if (digit > maximum % 10) {
        return 0;
                }
                }


value =value* 10 + digit;
position = position + 1;
                }
    if (value < minimum) {
        return 0;
                }
    *number = value;
    return 1;



                }

