#include <stdio.h>

void bubbleSort(int a[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        int swapped = 0;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                // Swap elements
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped) 
        {
            break;
        }
    }
}

int main() 
{
    int a[100], n, i;

    printf("Enter total elements of the array : ");
    scanf("%d", &n);

    printf("Enter %d elements : \n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    printf("Array Before Sorting : \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }

    bubbleSort(a, n);

    printf("\n\nAfter Sorting Array Elements : \n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
