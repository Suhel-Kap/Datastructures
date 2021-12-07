// 3. Write a program to implement Selection Sort.
#include<stdlib.h>
#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *arr,int size){
    int i,j,min;
    for(i=0;i<size-1;i++){
        min = i;
        for(j=i+1;j<size;j++)
            if(arr[j] < arr[min])
                min = j;
        swap(&arr[min],&arr[i]);
    }
}
void printArray(int *arr,int size){
    int i;
    for(i=0;i<size;i++)
        printf("%d ",*(arr+i));
    printf("\n");
}
int main(){
    int *arr;
    int i = 0;
    arr = (int*)malloc(1000*sizeof(int));
    for(i=0;i<1000;i++) arr[i] = 1000-i;
    int size = 1000;
    printf("Program written by enrollment number 200420107012\n");
    printf("Unsorted array: ");
    printArray(arr,size);
    selectionSort(arr,size);
    printf("Sorted array using selection sort: ");
    printArray(arr,size);
    return 0;
}