#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 100;

int main()
{
    FILE* file;
    file = fopen("circle.txt", "r");
    if (file == NULL) {
        printf("Error of oppening file!");
        return 1;
    }
    char* str1 = (char*)malloc(SIZE * sizeof(char));
    int countFigures = 0;
    while (fgets(str1, SIZE, file)) {
        countFigures++;
        checkerrors(str1, countFigures);
    }
    fclose(file);
    return 0;
}