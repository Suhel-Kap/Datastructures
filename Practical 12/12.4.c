// 5. Write a program to implement Insertion Sort.
#include <stdio.h>
void insertionSort(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
    insertionSort(arr, size);
    printf("Sorted array using insertion sort: ");
    printArray(arr, size);
    return 0;
}