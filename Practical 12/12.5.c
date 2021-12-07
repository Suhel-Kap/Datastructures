// 6. Write a program to implement Merge Sort.
#include <stdio.h>
#include <stdlib.h>
void merge(int *L,int leftCount,int *R,int rightCount,int *A){
    int i,j,k;
    // i to mark the index of the left subarray
    // j to mark the index of the right subarray
    // k to mark the index of the main array
    i=0;j=0;k=0;
    while(i<leftCount && j<rightCount){
        if(L[i] <= R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while(i<leftCount) A[k++] = L[i++];
    while(j<rightCount) A[k++] = R[j++];
}
void mergeSort(int *A,int n){
    int mid,i,*L,*R;
    if(n<2) return; // base condition - if 1 element in array, do nothing
    //create left and right subarrays
    //left array has elements of main array up to mid
    //right array has elements of main array up from mid to end
    mid = n/2;
    L = (int *)malloc(mid*sizeof(int));
    R = (int *)malloc((n-mid)*sizeof(int));
    for(i=0;i<mid;i++) L[i] = A[i];
    for(i=mid;i<n;i++) R[i-mid] = A[i];
    mergeSort(L,mid);
    mergeSort(R,n-mid);
    merge(L,mid,R,n-mid,A);
    free(L);
    free(R);
}
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}
int main()
{
    int arr[] = {7, 5, 9, 4, 3, 2, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Program written by enrollment number 200420107012\n");
    printf("Unsorted array: ");
    printArray(arr, size);
    mergeSort(arr,size);
    printf("Sorted array using merge sort: ");
    printArray(arr, size);
    return 0;
}