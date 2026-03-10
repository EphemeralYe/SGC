#include <stdio.h>
int main() 
{
    int row1, col1, row2, col2, i, j, k;

    printf("Enter the number of Matrix A Rows : ");
    scanf("%d", &row1);
    printf("Enter the number of Matrix A Columns : ");
    scanf("%d", &col1);
    printf("Enter the number of Matrix B Rows : ");
    scanf("%d", &row2);
    printf("Enter the number of Matrix B Columns : ");
    scanf("%d", &col2);

    // Rule: Columns of A must equal Rows of B
    if (col1 != row2) 
    {
        printf("Multiplication not possible! Columns of A must match Rows of B.\n");
        return 0;
    }

    int A[row1][col1], B[row2][col2], C[row1][col2];

    printf("Enter Matrix A elements : \n");
    for (i = 0; i < row1; i++) 
    {
        for (j = 0; j < col1; j++) 
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter Matrix B elements : \n");
    for (i = 0; i < row2; i++) 
    {
        for (j = 0; j < col2; j++) 
        {
            scanf("%d", &B[i][j]);
        }
    }

    

    // Multiplication Logic
    for (i = 0; i < row1; i++) 
    {
        for (j = 0; j < col2; j++) 
        {
            C[i][j] = 0; // Initialize cell
            for (k = 0; k < col1; k++) 
            {
                // Fix: Use += to accumulate the sum of products
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }

    printf("\nMatrix A * Matrix B : \n");
    for (i = 0; i < row1; i++) 
    {
        for (j = 0; j < col2; j++) 
        {
            printf("%d \t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
