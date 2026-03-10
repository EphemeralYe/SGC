#include <stdio.h>

void insertion_sort(int arr[], int n) 
{
    int i, j, key;

    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key
           to one position ahead of their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int n) 
{
    int i;
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[100], i, n;

    printf("Enter the total values of the array : ");
    scanf("%d", &n);

    printf("Enter %d elements of the array : \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("\nSorted Array : \n");
    insertion_sort(arr, n);
    printArr(arr, n);

    return 0;
}
