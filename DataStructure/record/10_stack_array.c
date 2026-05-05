#include<stdio.h>
#include<stdbool.h>
int stack[100], top=-1;


void pop()
{
    if(top==-1){
        printf("Stack Underflow");
    }
    else {
        int data=stack[top];
        top=top-1;
        printf("Element %d Removed from stack\n",data);
    }
}

void push()
{
    int n=sizeof(stack)/sizeof(stack[0]);
    if(top==n){
        printf("Stack Overflow\n");
    }
    else{
        top=top+1;
        printf("Enter the element: ");
        scanf("%d",&stack[top]);
        printf("Element %d Inserted to the stack\n",stack[top]);
    }
}

void display(){
    if(top==-1){
        printf("Stack is empty \n");
    }
    else {
        printf("Your Stack is: ");
        for(int i=0; i<=top; i++){
            printf("%d ", stack[i]);
        }
    }
}


int main(){
    int choice;
    while(true)
    {
        printf("\nSelect what operation you want to performe: \n\t1) Push\n\t2) Pop\n\t3) Display\n\t4) Exit\nYour choice: ");
        scanf("%d", &choice);
        if(choice==4){
            printf("Exiting from the operation\n");
            break;
        }
        else {
            switch(choice){
                case 1:
                    push();
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                default:
                    printf("Invalid Choice\n");
            };
        }
    };
    return 0;
}

/*
OUTPUT
Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 1
Enter the element: 20
Element 20 Inserted to the stack

Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 1
Enter the element: 69
Element 69 Inserted to the stack

Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 3
Your Stack is: 20 69 
Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 2
Element 69 Removed from stack

Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 3
Your Stack is: 20 
Select what operation you want to performe: 
        1) Push
        2) Pop
        3) Display
        4) Exit
Your choice: 4
Exiting from the operation
*/
