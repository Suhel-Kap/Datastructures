/* 2. Write a program to implement following operations on the Doubly linked list
(a) Insert a node at the front of the linked list.
(b) Insert a node at the end of the linked list.
(c) Delete a last node of the linked list.
(d) Delete a node before specified position.
(e) Display */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *lptr, *rptr;
};

struct node *first, *last;

struct node *create();
struct node *insert_front(struct node *start);
struct node *insert_end(struct node *start);
struct node *delete_last(struct node *start);
struct node *delelte_before(struct node *start);
void display();

void main()
{
    int choice;
    struct node *head;
    printf("program written by enrollment number 200420107012\n");
    do
    {
        printf("\n 1. Create a Node");
        printf("\n 2. Insert a node at the front of the linked list.");
        printf("\n 3. Insert a node at the end of the linked list.");
        printf("\n 4. Delete a last node of the linked list.");
        printf("\n 5. Delete a node before specified position.");
        printf("\n 6. Display.");
        printf("\n 0. Exit.\n");

        printf("\n Enter a choice! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;
        case 2:
            head = insert_front(head);
            break;
        case 3:
            head = insert_end(head);
            break;
        case 4:
            head = delete_last(head);
            break;
        case 5:
            head = delelte_before(head);
            break;
        case 6:
            display();
            break;
        default:
            break;
        }

    } while (choice != 0);
}

struct node *create()
{
    int val;

    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the value : ");
    scanf("%d", &val);

    new_node->info = val;
    new_node->lptr = NULL;
    new_node->rptr = NULL;

    first = new_node;
    last = new_node;

    return new_node;
}

struct node *insert_front(struct node *start)
{
    int val;

    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the value : ");
    scanf("%d", &val);

    new_node->info = val;
    new_node->rptr = first;
    new_node->lptr = NULL;

    first->lptr = new_node;
    first = new_node;

    return start;
}

struct node *insert_end(struct node *start)
{
    int val;

    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the value : ");
    scanf("%d", &val);

    new_node->info = val;
    new_node->lptr = last;
    new_node->rptr = NULL;

    last->rptr = new_node;
    last = new_node;

    return start;
}

struct node *delete_last(struct node *start)
{
    struct node *temp, *temp2;

    temp = first;

    while (temp->rptr != NULL)
    {
        temp2 = temp;
        temp = temp->rptr;
    }

    last = temp2;
    last->rptr = NULL;

    free(temp);

    return start;
}

struct node *delelte_before(struct node *start)
{
    int pos;
    struct node *temp, *temp2, *temp3;

    printf("\n Enter the position : ");
    scanf("%d", &pos);

    temp = first;

    for (int i = 1; i < pos - 1; i++)
    {
        temp2 = temp;
        temp = temp->rptr;
    }

    temp3 = temp->rptr;
    temp2->rptr = temp3;
    temp3->lptr = temp2;

    free(temp);

    return start;
}

void display()
{
    struct node *temp;

    temp = first;

    printf("\n The Linked List Contains");
    printf("\n-------------");
    while (temp != NULL)
    {
        printf("\n %d", temp->info);
        temp = temp->rptr;
    }
    printf("\n-------------\n");
}