// 4. Write a program to implement Bubble Sort.
#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *arr,int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++)
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
    }
}
void printArray(int *arr,int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}
int main(){
    int arr[] = {7,5,9,4,3,2,1,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Program written by enrollment number 200420107012\n");
    printf("Unsorted array: ");
    printArray(arr,size);
    bubbleSort(arr,size);
    printf("Sorted array using bubble sort: ");
    printArray(arr,size);
    return 0;
}