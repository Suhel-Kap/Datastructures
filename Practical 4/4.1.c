#include <stdio.h>
void push(int s[], int n, int *TOP, int x)
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
void pop(int s[], int *TOP)
{
    if (*TOP == -1)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        printf("%d", s[--*TOP + 1]);
    }
}
int DecToBin(int num)
{
    int s[30], TOP = -1;
    int n = sizeof s / sizeof s[0];
    while (num != 0)
    {
        int temp = num % 2;
        push(s, n, &TOP, temp);
        num /= 2;
    }
    while (TOP != -1)
    {
        pop(s, &TOP);
        TOP == -1 && printf("\n");
    }
}
int main()
{
    int intNum;
    printf("Program written by enrollment number 200420107012\n");
    printf("Enter the number : ");
    scanf("%d", &intNum);
    DecToBin(intNum);
    return 0;
}
