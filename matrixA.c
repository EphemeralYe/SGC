#include <stdio.h>
int main()
{
	int row,col,i,j,a[100][100],b[100][100],c[100][100];
	printf("rows of matrix a \n");
	scanf("%d",&row);
	printf("how many col if matrix b \n");
	scanf("%d",&col);
	printf("enter the elements of %d x %d matrix:",row,col);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the elements of 2nd matrix: \n");
	for(i=0;i<row;i++)
        {
                 for(j=0;j<col;j++)
                 {
                         scanf("%d",&b[i][j]);
                 }
	}
	printf("the sum of a and b are: \n");
	for(i=0;i<row;i++)          
        {
                 for(j=0;j<col;j++)
                 {
                         c[i][j]=a[i][j]+b[i][j];
                 }
        }
	for(i=0;i<row;i++)          
        {
                 for(j=0;j<col;j++)
                 {
			printf("%d",c[i][j]);
			printf("\t");
                 }
		 printf("\n");
        }
	return 0;
}
