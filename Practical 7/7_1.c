// 7.1 Write a C program to convert any infix expression in to postfix expression.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void infix_to_postfix(char infix[]);
int instack_priority(char ch);
int incoming_priority(char ch);
void push(char a);
char pop();

void main()
{
    printf("Program written by enrollment number 200420107012");
    char infix[100];

    printf("\n NOTE: Enter the infix Expression with starting and ending parenthesis");
    printf("\n Enter the Infix Expression : ");
    scanf("%s", infix);

    infix_to_postfix(infix);
}

void infix_to_postfix(char infix[100])
{
    int i = 0, len, j = 0;
    len = strlen(infix);

    char ch, postfix[100];

    stack[top] = '$';

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];
        while (instack_priority(stack[top]) > incoming_priority(ch))
        {
            postfix[j] = pop();
            j++;
        }

        if (instack_priority(stack[top]) != incoming_priority(ch))
        {
            push(ch);
        }
        else
        {
            pop();
        }
    }

    while ((ch = pop() != '$'))
    {
        postfix[j] = ch;
        j++;
    }

    postfix[j] = '\0';

    printf("\n The Postfix Expression is -> %s \n", postfix);
}

int instack_priority(char ch)
{
    int priority;

    switch (ch)
    {
    case '+':
        priority = 2;
        break;

    case '-':
        priority = 2;
        break;

    case '*':
        priority = 4;
        break;

    case '/':
        priority = 4;
        break;

    case '^':
        priority = 5;
        break;

    case '(':
        priority = 0;
        break;

    case '$':
        priority = -1;
        break;

    default:
        priority = 8;
        break;
    }

    return priority;
}

int incoming_priority(char ch)
{
    int priority;

    switch (ch)
    {
    case '+':
        priority = 1;
        break;

    case '-':
        priority = 1;
        break;

    case '*':
        priority = 3;
        break;

    case '/':
        priority = 3;
        break;

    case '^':
        priority = 6;
        break;

    case '(':
        priority = 9;
        break;

    case ')':
        priority = 0;
        break;

    default:
        priority = 7;
        break;
    }

    return priority;
}

void push(char a)
{
    top = top + 1;
    stack[top] = a;
}

char pop()
{
    char a;
    a = stack[top];
    top = top - 1;

    return a;
}
