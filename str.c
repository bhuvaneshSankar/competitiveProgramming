#include <stdio.h>
#include <string.h>

int main()
{
    char str[10][100];
    scanf("%s", str[0]);
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", str[i]);
    }
}