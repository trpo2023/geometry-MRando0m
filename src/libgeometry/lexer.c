#include <stdlib.h>
#include <string.h>

#define SIZE 100

int checker(char* str)
{
    int ret = 1;
    char* rec = (char*)malloc(SIZE * sizeof(char));
    for (int i = 0; i < (int)strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else {
            break;
        }
    }
    char figure[] = "circle";
    if (strcmp(rec, figure) == 0) {
        ret = 0;
    }
    return ret;
}
