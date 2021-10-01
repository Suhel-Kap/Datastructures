//2. Write a program to take two input variable from user and swap that values.
#include<stdio.h>
#include<conio.h>

int main(){

    int x,y,temp;
    printf("\nEnter value of x and y respectively\n");
    scanf("%d %d",&x,&y);

    temp = x;
    x = y;
    y = temp;
    printf("\nAfter Swaping x=%d and y=%d",x,y);
    getch();
    return 0;
}