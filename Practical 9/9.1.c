// To calculate and print factorial of a given number

#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    printf("Program written by enrollment number 200420107012\n");
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Factorial: %d\n", factorial(n));
    return 0;
}