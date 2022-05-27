#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[30];
    printf("Hey user get me some input :\n");
    fgets(input, 30, stdin);
    printf("Your input is : %s", input);
    return 0;
}
