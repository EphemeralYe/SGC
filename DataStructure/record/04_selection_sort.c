#include <stdio.h>
void selection(int arr[], int n) 
{
    int i = 0, j = 0, small, temp;
    for (i = 0; i < n - 1; i++) 
    {
        small = i; // Assume the first element is the smallest

        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[small]) 
            {
                small = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

void printArr(int a[], int n) 
{
    int i = 0;
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]); // Changed to space-separated for better readability
    }
    printf("\n");
}

int main() 
{
    int n, i = 0, num;

    printf("Enter total elements of the array : ");
    if (scanf("%d", &num) != 1) return 1;

    int a[num]; // Variable Length Array (C99)

    printf("Enter %d elements : \n", num);
    for (i = 0; i < num; i++) 
    {
        scanf("%d", &a[i]);
    }

    n = sizeof(a) / sizeof(a[0]);

    printf("Array Before Sorting : \n");
    printArr(a, n);

    selection(a, n);

    printf("\nAfter Sorting Array Elements : \n");
    printArr(a, n);

    return 0;
}
