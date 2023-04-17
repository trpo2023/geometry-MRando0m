#include <libgeometry/parser.h>
#include <libgeometry/povtor.h>
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
        if (checkerrors(str1, countFigures) == 0) {
            printf("\nPerimetr:%f\n", count_perimeter(str1));
            printf("Plosh:%f\n", count_area(str1));
        }
    }

    fclose(file);
    printf("\n");
    return 0;
}