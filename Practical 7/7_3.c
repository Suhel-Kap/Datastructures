// Write a C program to find whether given expression is in well formed or not(for all brackets for e.g ( , { , [ )

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 256

char stack[size];
int top = -1;

void push(char x)
{
    if (top >= size - 1)
    {
        printf("\nStack overflow");
        return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

char pop()
{
    if (top < 0)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    else
    {
        char x = stack[top];
        top--;
        return x;
    }
    return 0;
}

void display()
{
    int i = 0;
    for (i = 0; i <= top; i++)
    {
        printf("%c", stack[i]);
    }
    printf("\n");
}

int checkPara(char *str)
{
    int i = 0, res = 0;
    char x;
    while (i < strlen(str))
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            push(str[i]);
            i++;
        }
        if (str[i] == ')')
        {
            x = pop();
            if (x == '(')
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        else if (str[i] == ']')
        {
            x = pop();
            if (x == '[')
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
        else if (str[i] == '}')
        {
            x = pop();
            if (x == '{')
            {
                i++;
            }
            else
            {
                return 0;
            }
        }
    }
    if (top != -1)
    {
        res = 0;
    }
    else
    {
        res = 1;
    }
    return res;
}

int main()
{
    printf("Program written by enrollment number 200420107012\n");
    char toCheck[256], item;
    printf("Enter string to check for balanced paranthesis: ");
    scanf("%[^\n]s", toCheck);
    if (checkPara(toCheck))
    {
        printf("Balanced expression\n");
    }
    else
    {
        printf("Unbalanced expression\n");
    }
    return 0;
}