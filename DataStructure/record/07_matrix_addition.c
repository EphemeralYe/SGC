#include <stdio.h>

int main() 
{
    int a[100][100], b[100][100], c[100][100], i, j, rows, columns;

    printf("Enter the number of Rows : ");
    scanf("%d", &rows);
    printf("Enter the number of Columns : ");
    scanf("%d", &columns);

    printf("Enter Matrix A elements : \n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter Matrix B elements : \n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++) 
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Addition Logic
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++) 
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    

    printf("\nMatrix A + Matrix B : \n");
    for (i = 0; i < rows; i++) 
    {
        for (j = 0; j < columns; j++) 
        {
            printf("%d \t", c[i][j]);
        }
        printf("\n"); // Newline after each row for proper matrix formatting
    }

    return 0;
}
