#include <stdio.h>
#include <string.h>

#define N 50

int check_name(char* string)
{
    char temp[strlen(string)], len = 0;
    for (int i = 0; (string[i] > 96) && (string[i] < 123); i++) {
        if (string[i] != '(') {
            temp[i] = string[i];
            len = i;
        } else
            break;
    }
    if (strcmp(temp, "circle") == 0)
        return len + 1;
    else
        return 1;
}

int main()
{
    printf("Hello, world!");
    return 0;
}