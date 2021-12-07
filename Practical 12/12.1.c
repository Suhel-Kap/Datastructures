// Implement linear and binary search in C
#include <stdio.h>
int linearSearch(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int binarySearch(int arr[], int size, int key)
{
    int start = 0, end = size - 1, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int foundLs, foundBs, key;
    printf("Enter number to search: ");
    scanf("%d", &key);
    foundLs = linearSearch(arr, size, key);
    foundBs = binarySearch(arr, size, key);
    foundLs == -1 ? printf("Element not in array\n") : printf("Element present at index %d\n", foundLs);
    foundBs == -1 ? printf("Element not in array\n") : printf("Element present at index %d\n", foundBs);
    return 0;
}
