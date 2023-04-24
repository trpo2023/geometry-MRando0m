#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <libgeometry/area.h>
#include <libgeometry/perimetr.h>

#define COUNT_ARG 3

double* findofarg(char* str)
{
    double* arguments = (double*)malloc(COUNT_ARG * sizeof(double));
    int i = 0;
    int count = 0;
    char* temp = (char*)malloc(sizeof(char));
    for (; str[i] != '('; i++) {
    }
    i++;
    for (; str[i] != ' '; i++) {
        temp[count++] = str[i];
        temp = realloc(temp, (count + 1) * sizeof(char));
    }
    i++;
    count = 0;
    arguments[0] = atof(temp);
    free(temp);
    temp = (char*)malloc(sizeof(char));
    for (; str[i] != ','; i++) {
        temp[count++] = str[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    i++;
    count = 0;
    arguments[1] = atof(temp);
    free(temp);
    temp = (char*)malloc(sizeof(char));
    for (; str[i] != ')'; i++) {
        temp[count++] = str[i];
        temp = (char*)realloc(temp, (count + 1) * sizeof(char));
    }
    arguments[2] = atof(temp);
    free(temp);
    return arguments;
}

void intersections(char** lines, int row)
{
    double** arg = (double**)malloc(row * sizeof(double*));
    for (int i = 0; i < row; i++) {
        arg[i] = (double*)malloc(COUNT_ARG * sizeof(double));
        arg[i] = findofarg(lines[i]);
    }

    for (int i = 0; i < row; i++) {
        printf("\nFigure %d.\n %s", i + 1, lines[i]);
        printf("\tarea = %f\n", scoreArea(lines[i]));
        printf("\tperimetr = %f\n", scorePer(lines[i]));
        for (int j = 0; j < row; j++) {
            if (i != j) {
                float d
                        = sqrt(pow((arg[i][0] - arg[j][0]), 2)
                               + pow((arg[i][1] - arg[j][1]), 2));
                int r = 0, R = 0;
                if (arg[i][2] < arg[j][2]) {
                    r = arg[i][2];
                    R = arg[j][2];
                } else {
                    r = arg[j][2];
                    R = arg[i][2];
                }
                if (((d < (r + R)) && (R - r < d)) || (d == R + r)
                    || (d == R - r)) {
                    printf("\t\tIntersects:\n\t\t%d. circle\n", j + 1);
                }
            }
        }
    }
    for (int i = 0; i < row; i++) {
        free(arg[i]);
    }
    free(arg);
}
