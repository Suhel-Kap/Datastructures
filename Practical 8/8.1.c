/* 1. Write a program to implement following operations on the Circular linked list. Make a create() function to initially add few nodes in the circular linked list.

(a) Insert a node at the end of the linked list.
(b) Insert a node before specified position.
(c) Delete a first node of the linked list.
(d) Delete a node after specified position.
(e) Display */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *first, *last;

struct node *create();
struct node *insert_end(struct node *start);
struct node *insert_pos(struct node *start);
struct node *delete_first(struct node *start);
struct node *delete_after(struct node *start);
void display(struct node *start);
// Supporting Functions
int lenth(struct node *start);

void main()
{
    int choice;
    struct node *head;
    printf("program written by enrollment number 200420107012\n");
    do
    {
        printf("\n------------------------------------------------");
        printf("\n 1. Create a Circular Linked List.");
        printf("\n 2. Insert a node at the end of the linked list.");
        printf("\n 3. Insert a node before specified position.");
        printf("\n 4. Delete a first node of the linked list.");
        printf("\n 5. Delete a node after specified position");
        printf("\n 6. Display.");
        printf("\n 0. Exit.\n");
        printf("------------------------------------------------\n");

        printf("\n Enter a choice! : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create();
            break;

        case 2:
            head = insert_end(head);
            break;
        case 3:
            if (head == NULL)
            {
                printf("\n Linked List is Empty! Insert the element first!");
                exit(0);
            }
            head = insert_pos(head);
            break;
        case 4:
            head = delete_first(head);
            break;
        case 5:
            if (head == NULL)
            {
                printf("\n Linked List is Empty! Insert the element first!");
                exit(0);
            }
            head = delete_after(head);
            break;
        case 6:
            display(head);
            break;
        case 0:
            printf("\n Exiting the code...");
            exit(0);
        default:
            break;
        }

    } while (choice != 0);
}

struct node *create()
{
    int val;
    struct node *first_node;
    first_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the value: ");
    scanf("%d", &val);

    first_node->info = val;
    first_node->link = first_node;
    first = last = first_node;

    return first_node;
}

struct node *insert_end(struct node *start)
{
    int val;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the value: ");
    scanf("%d", &val);

    if (start == NULL)
    {
        new_node->info = val;
        new_node->link = new_node;
        first = last = new_node;
    }
    else
    {
        new_node->info = val;
        new_node->link = first;
        last->link = new_node;
        last = new_node;
    }

    return start;
}

struct node *insert_pos(struct node *start)
{
    int pos, val, len;
    struct node *new_node, *temp1, *temp2;
    new_node = (struct node *)malloc(sizeof(struct node));

    printf("\n Enter the position : ");
    scanf("%d", &pos);
    printf("\n Enter the value : ");
    scanf("%d", &val);

    len = lenth(start);

    if (pos == len)
    {
        printf("\n Invalid Position! There is no node before %d position!", pos);
        exit(0);
    }

    if (pos > len)
    {
        printf("\n Invalid Position! The Likedlist contains only %d elements", len);
        exit(0);
    }

    new_node->info = val;
    new_node->link = NULL;

    temp1 = first;

    for (int i = 0; i < pos - 1; i++)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }

    temp2->link = new_node;
    new_node->link = temp1;

    return start;
}

struct node *delete_first(struct node *start)
{
    struct node *temp, *temp1;

    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        exit(0);
    }

    temp = start->link;
    first = temp;
    temp1 = last;
    temp1->link = temp;

    free(start);

    return temp;
}

struct node *delete_after(struct node *start)
{
    int pos, len;
    struct node *temp1, *temp2;
    len = lenth(start);

    printf("\n Enter the position : ");
    scanf("%d", &pos);

    if (pos == len)
    {
        printf("\n Invalid Position! There is no node after %d position!", pos);
        exit(0);
    }

    if (pos > len)
    {
        printf("\n Invalid Position! The Likedlist contains only %d elements", len);
        exit(0);
    }

    temp1 = first;

    for (int i = 0; i < pos; i++)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }

    temp2->link = temp1->link;

    free(temp1);

    return start;
}

void display(struct node *start)
{
    int len;
    struct node *current;
    current = first;

    if (start == NULL)
    {
        printf("\n Linked List is Empty! Insert the element first!");
        exit(0);
    }

    printf("\n The Circular Linked List Contains:");

    do
    {
        printf("\n %d", current->info);
        current = current->link;
    } while (current != first);
}

int lenth(struct node *start) // Supporting Functions
{
    int len = 0;
    struct node *current;
    current = first;

    do
    {
        len++;
        current = current->link;
    } while (current != first);

    return len;
}