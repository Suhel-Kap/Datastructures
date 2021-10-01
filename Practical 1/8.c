//8. Implement a program for ARRAY that performs following operations using function.
//(a) INSERT (b) DELETE (c) DISPLAY (d) SEARCH (e) MAX

#include <stdio.h>

void insert(int n, int a[n], int index, int value);
void delete(int n, int a[n], int index);
void display(int n,int a[n]);
int search(int n, int a[n], int value);
void max(int n, int a[n]);

int main(){
    int i, a[20],n,query,index,value,exit = 0;
    
    printf("\nEnter length of array \n[Note : length should be less than 20]\n");
    scanf("%d",&n);

    printf("\nEnter values of each  element of array consisting %d elements one by one\n",n);

    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    while(exit!=1){

        printf("\nEnter \"1\" for INSERT, \"2\" for DELETE, \"3\" for DISPLAY, \"4\" for SEARCH, \"5\" for MAX and \"6\" to EXIT : ");
        scanf("%d",&query);

        switch(query){
            case 1:

                if(n==20){
                    printf("\nLength of array is 20 thus more value can be added.");
                    break;
                }

                printf("\nEnter position at which value is to be inserted : ");
                scanf("%d",&index);

                if(index<0 || index>n+1){
                    printf("\nInvalid position entered.\nPlease try again.");
                    break;
                }

                printf("\nEnter value which is to be inserted : ");
                scanf("%d",&value);
                insert(n,a,index-1,value);
                n++;
                break;

            case 2:

                if(n==0){
                    printf("\nLength of array is 0 thus nothing can be deleted.");
                    break;
                }

                printf("\nEnter position at which value is to be inserted : ");
                scanf("%d",&index);

                if(index<0 || index>n){
                    printf("\nInvalid position entered.\nPlease try again.");
                    break;
                }
                delete(n,a,index-1);
                n--;
                break;

            case 3:

                if(n==0){
                    printf("\nArray is empty");
                    break;
                }
                display(n,a);
                break;

            case 4:

                printf("\nEnter value to be searched : ");
                scanf("%d",&value);

                int index = search(n,a,value);;
                if(index == -1){
                    printf("%d is not in the array",value);
                    break;
                }
                printf("\n%d is at position %d in the array",value,index+1);
                break;
            case 5:
                max(n,a);
                break;
            case 6:
                exit = 1;
                break;
            default :
                printf("Invalid number entered!");
        }
    }

    
    return 0;
}

void insert(int n, int a[n], int index, int value){
    int i, temp1, temp = a[index];
    a[index] = value;
    for(i = index+1; i <= n; i++){
        temp1 = a[i];
        a[i] = temp;
        temp = temp1;
    }
}

void delete(int n, int a[n], int index){
    int i;

    for(i = index; i < n; i++){
        a[i]=a[i+1];
    }
}

void display(int n,int a[n]){
    int i = 0;
    
    printf("\nElements of array are :");

    for(i = 0; i < n; i++){
        printf("\n%d",a[i]);
    }
}

int search(int n, int a[n], int value){
    int index;
    for(index = 0; index < n; index++){
        if(a[index]==value){
            return index;
        }
    }
    return -1;
}

void max(int n, int a[n]){
    int max, i = 0;

    for(i = 0; i < n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }

    printf("Maximum value in the array is %d",max);
}