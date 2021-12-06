// To find length of the string
#include <stdio.h>
int length(char *str)
{
    if (*str == '\0')
        return 0;
    return 1 + length(str + 1);
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    char str[50];
    printf("Enter string: ");
    scanf("%[^\n]s", str);
    printf("Length of string %s is %d\n", str, length(str));
    return 0;
}