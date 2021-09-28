// Write a menu driven program to implement following operations on the singly linked list. Design a function create to create a link list (which is required to be called only for one time for a link list)

// (a) create [ node * create() ]

// (b) display [ void display(node *start) ]

// (c) length [ int length (node *start) ]

// (d) maximum [int maximum (node *start)]

// (e) merge (to merge two link list in to the third one) [node * merge(node *start1, node *start2)

// (f) sort [void sort(node *start) ]

// (g) reverse [ node * reverse (node *start)]

// h) Insert a node at the front of the linked list. [ node * insert_front(node *start, int no) ]

// (i) Insert a node at the end of the linked list. [ node * insert_end(node *start, int no) ]

// (j) Insert a node such that linked list is in ascending order.(according to info. Field) [ node * insert_sort(node *start, int no) ]

// (k) Delete a first node of the linked list. [ node * delete_first(node *start) ]

// (l) Delete a node before specified position. [ node * delete_before(node *start, int pos) ]

// (m) Delete a node after specified position. [ node * delete_after(node *, int pos) ]

// (n) No search [ int search (node*, int x) ]

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node* create(){
  struct node *head = (struct node*)malloc(sizeof(struct node));
  int data;
  printf("Enter value of head node: ");
  scanf("%d",&data);
  head->data = data;
  head->next = NULL;
  printf("Linked list created, head at %p\n\t\tValue = %d\n",head,head->data);
  return head;
}

void display(struct node* head){
  while(head!=NULL){
    printf("%d -> ",head->data);
    head = head->next;
  }
  printf("NULL\n");
}

int length(struct node* head){
  int counter = 0;
  while(head!=NULL){
    counter++;
    head = head->next;
  }
  return counter;
}

int maximum(struct node* head){
  int max = head->data;
  while(head != NULL){
    if(head->data > max) 
      max = head-> data;
    head = head->next;
  }
  return max;
}
struct node* merge(struct node* start1, struct node* start2){}
void sort(struct node* head){}
struct node* reverse(struct node* head){}

struct node* insertAtHead(struct node* head, int data){
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = head;
  return temp;
}

struct node* insertAtTail(struct node* head, int data){
  struct node *temp = head, *temp2;
  while(temp->next != NULL)
    temp = temp->next;
  temp2 = (struct node*)malloc(sizeof(struct node));
  temp2->data = data;
  temp2->next = NULL;
  temp->next = temp2;
  return head;
}

struct node* insertSort(struct node* head, int data){}
struct node* deleteAtHead(struct node* head){}
struct node* deleteBefore(struct node* head, int pos){}
struct node* deleteAfter(struct node* head, int pos){}
int search(struct node* head, int x){}

int main(){
  int menu=0;
  struct node *head1,*head2,*head3;
  printf("Program written by enrollment number 200420107012\n1. Create\n2. Display\n3. Length\n4. Maximum\n5. Merge\n6. Sort\n7. Reverse\n8. Insert at head\n9. Insend\n10. Insord\n11. Delete head\n12. Delete before\n13. Delete After\n14. Search\n15. Exit\n");
  while (menu != 15){
    printf("Enter a choice: ");
    scanf("%d",&menu);
    switch(menu){
      case 1:
        head1 = create();
        break;
      case 2:
        display(head1);
        break;
      case 3:;
        int len;
        len = length(head1);
        printf("There are %d elements in the LL\n",len);
        break;
      case 4:;
        int max;
        max = maximum(head1);
        printf("Maximum value in the LL is %d\n",max);
        break;
      case 5:
        head2 = create();
        int data2;
        printf("Enter value of next element for LL2: ");
        scanf("%d",&data2);
        head2 = insertAtTail(head2,data2);
        head3 = merge(head1,head2);
        display(head3);
        break;
      case 6:
        printf("Sorting list...\n");
        sort(head1);
        display(head1);
        break; 
      case 7:;
        printf("Reversing list...\n");
        struct node *reverseHead = reverse(head1);
        display(reverseHead);
        break;
      case 8:;
        int dataH;
        printf("Enter value of node: ");
        scanf("%d",&dataH);
        head1 = insertAtHead(head1,dataH);
        break;
      case 9:;
        int dataT;
        printf("Enter value of node: ");
        scanf("%d",&dataT);
        head1 = insertAtTail(head1,dataT);
        break;
      case 10:;
        int dataS;
        printf("Enter value of node: ");
        scanf("%d",&dataS);
        head1 = insertSort(head1,dataS);
        break;
      case 11:
        head1 = deleteAtHead(head1);
        display(head1);
        break;
      case 12:;
        int posB;
        printf("Enter position: ");
        scanf("%d",&posB);
        head1 = deleteBefore(head1,posB);
        display(head1);
        break;
      case 13:;
        int posA;
        printf("Enter position: ");
        scanf("%d",&posA);
        head1 = deleteAfter(head1,posA);
        display(head1);
        break;
      case 14:;
        int x,result;
        printf("Enter data to search: ");
        scanf("%d",&x);
        result = search(head1,x);
        (result == -9999) ? printf("Value not found in linked list!\n") : printf("%d found in linked list\n",result);
        break;
      case 15:
        return 0;
      default:
        printf("Choose correct option\n");
        break;
    }
    menu=0;
  }
  return 0;
}
