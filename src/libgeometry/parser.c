#include <libgeometry/lexer.h>
#include <libgeometry/parser.h>

#include <stdio.h>
#include <string.h>

int checkarg(char* str)
{
    int count = 0;
    for (int i = 7; str[i] != ',' && i < (int)strlen(str); i++) {
        if ((str[i] != '.' && str[i] != ' ')
            && !(str[i] >= 48 && str[i] <= 57)) {
            return 2;
        }
        if (str[i] >= 48 && str[i] <= 57 && str[i + 1] == ' ')
            count++;
        if (str[i] == '.' && str[i + 1] == ')')
            count += 2;
    }
    if (count + 1 != 2) {
        return 2;
    }
    int index = 0;
    for (int i = 0; i != (int)strlen(str); i++) {
        if (str[i] == ',') {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }
    for (; str[index] != ')' && index < (int)strlen(str); index++) {
        if ((str[index] != '.' && str[index] != ' ')
            && !(str[index] >= 48 && str[index] <= 57)) {
            return 4;
        }
        if (str[index] >= 48 && str[index] <= 57 && str[index + 1] == ' ')
            count++;
        if (str[index] == '.' && str[index + 1] == ' ')
            count += 2;
    }
    if (count != 1) {
        return 4;
    }
    return 0;
}

int checkarguments(char* str)
{
    if (str[strlen(str) - 3] != ')') {
        return 5;
    }
    return 0;
}

int circlis(char* str)
{
    if (checker(str) == 1)
        return 1;

    if (checkarg(str) == 2)
        return 2;

    if (checkarg(str) == 3)
        return 3;

    if (checkarguments(str) == 4)
        return 4;

    if (checkarguments(str) == 5)
        return 5;

    return 0;
}

void checkerrors(char* line, int check, int countFigures)
{
    printf("\nFigure %d.\n %s", countFigures, line);
    switch (check) {
    case 1:
        printf(" Incorrect input of figure name\n");
        break;
    case 2:
        printf(" Figure coordinates entered incorrectly\n");
        break;
    case 3:
        printf(" Figure radius entered incorrectly\n");
        break;
    case 4:
        printf(" Wrong final symbol\n");
        break;
    case 5:
        printf(" Wrong final symbol\n");
        break;
    }
}
