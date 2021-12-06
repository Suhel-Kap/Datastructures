// To print nth Fibonacci number
#include <stdio.h>
int fibo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    int n;
    printf("Enter nth number of fibonacci series: ");
    scanf("%d", &n);
    printf("The number at %d position of fibonacci series is: %d\n", n, fibo(n));
    return 0;
}