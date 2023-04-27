#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <libgeometry/intersections.h>
#include <libgeometry/parser.h>

#define SIZE 100

int main()
{
    FILE* file;
    file = fopen("circle.txt", "r");
    if (file == NULL) {
        printf("Error file oppen!");
        return 1;
    }
    char* line = (char*)malloc(SIZE * sizeof(char));
    char** lines = (char**)malloc(sizeof(char*));
    int row = 1, num = 1;
    while (fgets(line, SIZE, file)) {
        int check = circlis(line);
        if (!check) {
            lines = (char**)realloc(lines, row * sizeof(char*));
            lines[row - 1] = (char*)malloc(strlen(line) * sizeof(char));
            strcpy(lines[row - 1], line);
            row++;
        } else {
            checkerrors(line, check, num++);
        }
    }
    fclose(file);

    printf("\n\nCorrect figures in WKT format:");
    intersections(lines, row - 1);

    for (int i = 0; i < row - 1; i++) {
        free(lines[i]);
    }
    free(lines);
    free(line);
    printf("\n");
    return 0;
}
