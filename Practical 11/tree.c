// Write a program for binary search tree to demonstrate following functionalities :

//     1) Create/insert tree,

//     2) Recursive and non recursive tree traversals inorder, preorder and post order,

//     3) Delete operation

#include <stdio.h>
#include <stdlib.h>

struct BstNode {
    char data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *getNewNode(char data){
    struct BstNode *newNode = (struct BstNode*)malloc(sizeof(struct BstNode *));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

struct BstNode *insert(struct BstNode *root, char data){
    if (root == NULL) {
        root = getNewNode(data);
    } else if (data <= root->data){
        root->left = insert(root->left,data);
    } else {
        root->right = insert(root->right,data);
    }
    return root;
}

void preorder(struct BstNode *root){
    if (root == NULL) return;
    printf("%c ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct BstNode *root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}

void postorder(struct BstNode *root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}

struct BstNode *s1[256],*s2[256];
int TOP1 = -1,TOP2 = -1;

// Helper functions of stack

void push(struct BstNode *root,struct BstNode **s,int *TOP){
    (*TOP)++;
    s[*TOP] = root;
}

struct BstNode *pop(struct BstNode **s, int *TOP){
    return s[(*TOP)--];
}

void preorderNR(struct BstNode *root){
    struct BstNode *current = root;
    int done = 0;
    while(!done){
        if(current != NULL){
            push(current,s1,&TOP1);
            printf("%c ",current->data);
            current = current->left;
        } else {
            if (TOP1 != -1){
                current = pop(s1,&TOP1);
                current = current->right;
            } else {
                done = 1;
            }
        }
    }
}

void inorderNR(struct BstNode *root){
    struct BstNode *current = root;
    int done = 0;
    while(!done){
        if(current != NULL){
            push(current,s1,&TOP1);
            current = current->left;
        } else {
            if (TOP1 != -1){
                current = pop(s1,&TOP1);
                printf("%c ",current->data);
                current = current->right;
            } else {
                done = 1;
            }
        }
    }
}

void postorderNR(struct BstNode *root){
    if (root == NULL) return;

    push(root,s1,&TOP1);
    struct BstNode *current;
    while(TOP1 != -1){
        current = pop(s1,&TOP1);
        push(current,s2,&TOP2);
        if(current->left != NULL) push(current->left,s1,&TOP1);
        if(current->right != NULL) push(current->right,s1,&TOP1);
    }
    while(TOP2 != -1){
        current = pop(s2,&TOP2);
        printf("%c ",current->data);
    }
}

struct BstNode *findMax(struct BstNode *root){
    if (root == NULL) return root;
    while(root->right != NULL) root = root->right;
    return root;
}

struct BstNode *Delete(struct BstNode *root,char data){
    if(root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left,data);
    else if (data > root->data) root->right = Delete(root->right,data);
    else { // Element found
        if (root->left == NULL && root->right == NULL){ // leaf node
            free(root);
            root = NULL;
        } else if (root->left == NULL) { // only right child exists
            struct BstNode *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL){ // only left child exists
            struct BstNode *temp = root;
            root = root->left;
            free(temp);
        } else { // both children exist
            struct BstNode *temp = findMax(root->left); // find max element of left subtree
            root->data = temp->data;
            root->left = Delete(root->left,temp->data);
        }
    }
    return root;
}

int main(){
    struct BstNode *root;
    root = insert(root,'f'); insert(root,'d'); insert(root,'j'); insert(root,'b'); insert(root,'e'); 
    insert(root,'g'); insert(root,'k'); insert(root,'a'); insert(root,'c'); insert(root,'h');

    printf("Program written by enrollment number 200420107012\n");
    printf("Preorder traversal of tree: "); 
    preorder(root); printf("\n");
    printf("Inorder traversal of tree: "); 
    inorder(root); printf("\n");
    printf("Postorder traversal of tree: "); 
    postorder(root); printf("\n");
    printf("Preorder non-recursive traversal of tree: "); 
    preorderNR(root); printf("\n");
    printf("Inorder non-recursive traversal of tree: "); 
    inorderNR(root); printf("\n");
    printf("Postorder non-recursive traversal of tree: "); 
    postorderNR(root); printf("\n");
    printf("Deleting f");
    root = Delete(root,'f');
    printf("\nPostorder non-recursive traversal of tree: "); 
    postorderNR(root); printf("\n");
    return 0;
}