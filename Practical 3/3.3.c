#include<stdio.h>
#define max_size 100

int arr[max_size];
int top = -1;
void push(int x);
void pop();
void peep(int pos);
void change(int x);
void display();

void main()
{
  printf("Program written by enrollment number 200420107012\n");
  push(2); //push 2 in stack
  push(3); //push 3 in stack
  push(5); //push 5 in stack
  push(9); // push 9 in stack
  display(); //display all elements
  pop(); //delete top element of stack
  display(); //display all elements
  change(4); // change value of top element to value '4'
  display(); //display all the element in the stack
  peep(2); // display element of stack at pos 2
}

void push(int x){
  if(top == max_size-1){
    printf("\nStack overflow");
    return;
  }
  arr[++top] = x;
}

void pop()
{
  if(top==-1)
  {
    printf("\nStack is empty");
    return;
  }
  top--;
}

void peep(int pos)
{
  if((pos-1)>top)
  {
    printf("\nInvalid position");
    return;
  }
  printf("\nThe value of element at position-%d : %d.\n",pos,arr[pos-1]);
}

void change(int p)
{
  arr[top]=p;
}

void display()
{
  int i;
  if(top==-1)
  {
    printf("\nStack is empty");
    return;
  }
  printf("\nStack ::");
  for(i=0;i<=top;i++)
  {
    printf(" %d",arr[i]);
  }
}