#include <stdio.h>

#define QUEUE_SIZE 100 // Using #define is more standard for array sizes in C

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int value) 
{
    if (rear >= QUEUE_SIZE - 1) 
    {
        printf("Queue Overflow \n");
    } 
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d \n", value);
    }
}

void dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue Underflow \n");
        front = rear = -1; // Reset queue when empty
    } 
    else 
    {
        int dequeued = queue[front];
        printf("Dequeued %d \n", dequeued);
        front++;
        
        if (front > rear) // Reset queue when empty
        {
            front = rear = -1;
        }
    }
}

void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty \n");
    } 
    else 
    {
        printf("Queue elements (front to rear): \n");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d ", queue[i]); // Changed to space-separated for clarity
        }
        printf("\n");
    }
}

int main() 
{
    int choice, value;

    while (1) 
    {
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) 
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again. \n");
                break;
        }
    }

    return 0;
}#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
typedef struct 
{
    char items[MAX];
    int top;
} Stack;

void initStack(Stack *s) 
{
    s->top = -1;
}

void push(Stack *s, char c) 
{
    if (s->top < MAX - 1) 
    {
        s->items[++s->top] = c;
    }
}

char pop(Stack *s) 
{
    if (s->top != -1) 
    {
        return s->items[s->top--];
    }
    return '\0';
}

char peek(Stack *s) 
{
    if (s->top != -1) 
    {
        return s->items[s->top];
    }
    return '\0';
}

int precedence(char op) 
{
    // Fixed: Removed space from ' -'
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void reverseString(char *str) 
{
    int len = strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) 
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char *infix, char *prefix) 
{
    Stack s;
    initStack(&s);
    reverseString(infix);

    // Swap brackets and fix null terminator check
    for (int i = 0; infix[i] != '\0'; i++) 
    {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    int j = 0;
    for (int i = 0; infix[i]; i++) 
    {
        if (isalnum(infix[i])) 
        {
            prefix[j++] = infix[i];
        } 
        else if (infix[i] == '(') 
        {
            push(&s, infix[i]);
        } 
        else if (infix[i] == ')') 
        {
            while (s.top != -1 && peek(&s) != '(') 
            {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        } 
        else 
        {
            // For Prefix, we handle operators with equal precedence slightly differently
            // but for syntax fixing, I kept your core logic structure.
            while (s.top != -1 && precedence(peek(&s)) > precedence(infix[i])) 
            {
                prefix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (s.top != -1) 
    {
        prefix[j++] = pop(&s);
    }
    prefix[j] = '\0';

    reverseString(prefix);
}

int main() 
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
