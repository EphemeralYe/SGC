#include<stdio.h>
int binarySearch(int arr[], int key, int n)
{ 
    int start=0, end=n-1, mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else if(arr[mid]<key){
            start=mid+1;
        }
    }
    return -1;
}
void printArr(int arr[], int n)
{
    printf("Your Array is : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n, key, result;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d Elements:\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printArr(arr, n);
    printf("\nEnter the element you need to srearch: ");
    scanf("%d",&key);
    result=binarySearch(arr,key,n);
    if (result!=-1){
        printf("The Element %d Found at the position %d\n",key, result+1);
    }
    else{
        printf("Element not found");
    }
}


/* OUTPUT
Enter the number of elements: 5
Enter 5 Elements:
1
2
3
4
5
Your Array is : 1 2 3 4 5 
Enter the element you need to srearch: 5
The Element 5 Found at the position 5
*/
