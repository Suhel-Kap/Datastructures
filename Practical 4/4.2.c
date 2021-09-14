#include <stdio.h>
#include <string.h>
void push(char s[], unsigned int n, int *TOP, char x)
{
    if (*TOP == n - 1)
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        s[++*TOP] = x;
    }
}
void pop(char s[], int *TOP)
{
    if (*TOP == -1)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("%c", s[--*TOP + 1]);
    }
}
int reverseString(char string[])
{
    char s[20];
    int TOP = -1, i = 0;
    unsigned int n = strlen(string);
    while (i < n)
    {
        push(s, n, &TOP, string[i++]);
    }
    while (TOP != -1)
    {
        pop(s, &TOP);
        TOP == -1 && printf("\n");
    }
}
int main()
{
    char string[20];
    printf("Program written by enrollment number 200420107012\n");
    printf("Enter String to be reversed : ");
    scanf("%[^\n]s", string);
    reverseString(string);
    return 0;
}
