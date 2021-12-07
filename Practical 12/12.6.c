// 7. Write a program to implement quick sort
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *arr, int start, int end)
{
    int partitionIndex = start, i;
    int pivot = arr[end];
    for (i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}
void quickSort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int partIndex = partition(arr, start, end);
    quickSort(arr, start, partIndex - 1);
    quickSort(arr, partIndex + 1, end);
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
    quickSort(arr, 0, size - 1);
    printf("Sorted array using quick sort: ");
    printArray(arr, size);
    return 0;
}