#include <stdio.h>

int fibonacci(int n) 
{
    if (n == 0) 
    {
        return 0;
    } 
    else if (n == 1) 
    {
        return 1;
    } 
    else 
    {
        // Recursive step: F(n) = F(n-1) + F(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() 
{
    int n, i;

    printf("Enter the number of terms : ");
    if (scanf("%d", &n) != 1) return 1;

    if (n <= 0) 
    {
        printf("Please enter a positive integer.\n");
    } 
    else 
    {
        printf("Fibonacci Series : ");
        for (i = 0; i < n; i++) 
        {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}
