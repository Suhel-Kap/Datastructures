// To solve Tower of Hanoi Problem for given number of disks
#include <stdio.h>
void towerOfHanoi(int n, char source, char dest, char inter)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }
    towerOfHanoi(n - 1, source, inter, dest);
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    towerOfHanoi(n - 1, inter, dest, source);
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    int n = 3;                      // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    return 0;
}