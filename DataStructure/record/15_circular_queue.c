#include<stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front=-1, rear=-1;


int isEmpty(){
    return rear==-1;
}
int isFull(){
    return ((rear+1)% MAX_SIZE) == front;
}

void enqueue(int value){
    if (isFull()){
        printf("Queue overflow\n");
    }
    if (front==-1){
        front=0;
    }
    rear=(rear+1)%MAX_SIZE;
    queue[rear]=value;
    printf("Element %d insrted\n", value);
}

void dequeue(){
    if(isEmpty()){
        printf("Queue underflow\n");
        return;
    }
    int data=queue[front];
    if(front==rear)
    {
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX_SIZE;
    }
    printf("Element %d removed\n", data);
}

void display(){
    if(isEmpty()){
        printf("Queue is Empty");
    }
    printf("Queue elements are: ");
    int i=front;
    while(i!=rear)
    {
        printf("%d ", queue[i]);
        i=(i+1)%MAX_SIZE;
    }
    printf("%d \n", queue[rear]);
}

int main(){
    enqueue(10);
    display();
    enqueue(15);
    display();
    dequeue();    
    display();
    dequeue(); 
    dequeue(); 
    return 0;
}


//OUTPUT

// Element 10 insrted
// Queue elements are: 10 
// Element 15 insrted
// Queue elements are: 10 15 
// Element 10 removed
// Queue elements are: 15 
// Element 15 removed
// Queue underflow
