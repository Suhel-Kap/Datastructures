// multiply two numbers using recursion
#include <stdio.h>
int product(int a, int b)
{
    if (a < b)
        return product(b, a);
    else if (b != 0)
        return (a + product(a, b - 1));
    else
        return 0;
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    int n1, n2, res = 0;
    printf("Enter two numbers to multiply: ");
    scanf("%d %d", &n1, &n2);
    res = product(n1, n2);
    printf("Result: %d\n", res);
    return 0;
}