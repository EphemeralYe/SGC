#include <stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void show();

int main() 
{
    printf("Enter the number of elements in the stack : ");
    scanf("%d", &n);

    printf("\n*******Stack Operations Using Array******* \n\n");

    while (choice != 4) 
    {
        printf("\nChoose one from the below options : \n");
        printf("\t1 - Push\n\t2 - Pop\n\t3 - Show\n\t4 - Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                printf("Exiting from the program... \n");
                return 0;
            default:
                printf("Invalid Choice. Please enter a valid choice\n");
                break;
        }
    }
    return 0;
}

void push() 
{
    int val;
    if (top == n - 1) 
    {
        printf("Overflow \n");
    } 
    else 
    {
        printf("Enter the value : ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop() 
{
    if (top == -1) 
    {
        printf("Underflow \n");
    } 
    else 
    {
        printf("Popped element: %d\n", stack[top]); // Added for better feedback
        top = top - 1;
    }
}

void show() 
{
    if (top == -1) 
    {
        printf("Stack is empty \n");
    } 
    else 
    {
        printf("Stack elements: \n");
        for (i = top; i >= 0; i--) 
        {
            printf("%d \n", stack[i]);
        }
    }
}
