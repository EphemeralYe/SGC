#include <stdio.h>
int fact(int n) 
{
    if (n == 0) 
    {
        return 1;
    } 
    else 
    {
        // Recursive step: n * (n-1)!
        return n * fact(n - 1);
    }
}

int main() 
{
    int n, f;

    printf("Enter a number to find factorial: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 0) 
    {
        printf("Factorial of a negative number is not defined.\n");
    } 
    else 
    {
        f = fact(n);
        printf("Factorial of %d = %d \n", n, f);
    }

    return 0;
}
