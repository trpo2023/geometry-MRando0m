#include <stdio.h>
#include <string.h>

#define N 50

int checker(char* string)
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
int check_values(char* string, int len)
{
    if (string[len] != '(') {
        printf("Error at column %d: expected '('\n", len);
        return 1;
    }
    char arg_count = 0, arg2_count = 0, d = 0, b = 0;
    for (int i = len + 1; (i < strlen(string)) && (string[i] != ','); i++) {
        if ((string[i] != ' ') && (string[i] != '.')
            && (!((string[i] > 47) && (string[i] < 58)))) {
            printf("Error at column %d\n", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' ')) {
            arg_count += 1;
            d = i;
        } else if ((string[i] == '.') && (string[i + 1] == ')')) {
            arg_count += 3;
            d = i;
        }
    }
    if ((arg_count != 1)) {
        printf("Error at column %d: too many|less args\n", d);
        return 1;
    }
    int v = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ',') {
            v = i + 1;
        }
    }
    for (int i = v; (string[i] != ')') && (i < strlen(string)) - 1; i++) {
        if (((string[i] != ' ') && (string[i] != '.')
             && (!((string[i] > 47) && (string[i] < 58))))
            || (string[i] == ',')) {
            printf("Error at column %d: \n", i);
            return 1;
        }
        if ((string[i] > 47) && (string[i] < 58) && (string[i + 1] == ' ')) {
            arg2_count += 1;
            b = i;
        } else if ((string[i] == '.') && (string[i + 1] == ' ')) {
            arg2_count += 2;
            b = i;
        }
    }
    if ((arg2_count != 1) && (b != 0)) {
        printf("Error at column %d: too many|less args\n", b);
        return 1;
    }
    return 0;
}
int main()
{
    printf("Hello, world!");
    return 0;
}