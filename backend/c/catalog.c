#include <stdio.h>
#include <string.h>
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

int next_data_line(FILE *file, char line [], int capacity, int*line_number) {
while (1) {
    char * read_result = fgets (line, capacity, file);
    if (read_result == NULL) {
    if (ferror(file)) {
        return -1;
                }
        return 0;
                }

    *line_number = * line_number + 1;
    int length = (int)strlen(line);
        if (length > 0 && line[length -1] == '\n') {
            line[length - 1] = '\0';
            length = length -1;
                }
        else {
        int character =fgetc(file);
        if (character !=EOF) {
            return -1;
                }
        if (ferror(file)) {
            return -1;
                }
                }
        if (length > 0 && line[length - 1] == '\r') {
            line[length - 1] = '\0';
                }
        if (line[0] != '\0' && line [0] != '#') {
            return 1;

                }
                }
                }
