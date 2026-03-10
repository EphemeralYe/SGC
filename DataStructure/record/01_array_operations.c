#include <stdio.h>
void traversal(int *a, int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int insertion(int *a, int n) {
    int pos, num;
    printf("Enter the position (1 to %d): ", n + 1);
    scanf("%d", &pos);
    printf("Enter the value to be inserted: ");
    scanf("%d", &num);

    pos = pos - 1;

    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = num;
   
    return n + 1; 
}
int deletion(int *a, int n) {
    int pos;
    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    pos = pos - 1;
    for (int i = pos; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    
    return n - 1;
}
int merge(int *a, int n) 
{
    int nn, b[100];

    printf("How many new elements? ");
    scanf("%d", &nn);

    printf("Enter the %d elements: ", nn);
    for(int i = 0; i < nn; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < nn; i++) {
        a[n + i] = b[i]; 
    }
    int total_elements = n + nn;
    return total_elements; 
}
int main() {
    int a[100], n, op;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("\n1) Insertion\n2) Deletion\n3) Traversal\n4)Merge\n");
    printf("Choose option: ");
    scanf("%d", &op);

    switch (op) {
        case 1:
                n= insertion(a, n);
                traversal(a, n);
                break;
        case 2:
                n=deletion(a, n);
                traversal(a, n);
                break;
	case 3:
        	traversal(a, n);
                break;
	case 4:
		n=merge(a,n);
		traversal(a,n);
		break;
        default:
                printf("Invalid option!\n");
    }
    return 0;
}
