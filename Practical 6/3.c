// Write a program to implement queue using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else
    {
        struct node *temp = front;
        front = front->next;
        printf("%d dequeued\n", temp->data);
        free(temp);
    }
}

void display()
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("Program written by enrollment number 200420107012\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(60);
    display();
    return 0;
}