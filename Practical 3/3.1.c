/*Introduction to pointers. Write a C program to swap two values using Call by Value and Call by reference.*/

#include<stdio.h>

void swap1(int a,int b)
{
  int temp;
  temp=a;
  a=b;
  b=temp;
  printf("\nAfter swapping values of a and b... \n a = %d \n b = %d",a,b);
}
void swap2(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void main()
{
  int a,b;
  printf("Program written by enrollment number 200420107012");
  printf("\nEnter value of a: ");
  scanf("%d",&a);
  printf("Enter value of b: ");
  scanf("%d",&b);

  printf("\nCalling function by value");
  swap1(a,b);

  printf("\nCalling function by refrence");
  swap2(&a,&b);
  printf("\nAfter swapping values of a and b... \n a = %d \n b = %d\n",a,b);
}
