#include <stdio.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct 
{
    int items[MAX];
    int top;
} Stack;

void initStack(Stack *s) 
{
    s->top = -1;
}

void push(Stack *s, int value) 
{
    if (s->top < MAX - 1) 
    {
        s->items[++s->top] = value;
    }
}

int pop(Stack *s) 
{
    if (s->top != -1) 
    {
        return s->items[s->top--];
    }
    return 0; // Return 0 if stack underflow
}

int evaluatePostfix(char *postfix) 
{
    Stack s;
    initStack(&s);
    int i, op1, op2;

    // Fixed: Removed the space from the null terminator check
    for (i = 0; postfix[i] != '\0'; i++) 
    {
        if (isdigit(postfix[i])) 
        {
            push(&s, postfix[i] - '0'); // Convert char digit to int
        } 
        else 
        {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (postfix[i]) 
            {
                case '+': push(&s, op1 + op2); break;
                case '-': push(&s, op1 - op2); break;
                case '*': push(&s, op1 * op2); break;
                case '/': 
                    if (op2 != 0) push(&s, op1 / op2); 
                    else printf("\nError: Division by zero\n");
                    break;
            }
        }
    }
    return pop(&s);
}

int main() 
{
    char postfix[MAX];

    printf("Enter postfix expression (e.g., 23+): ");
    scanf("%s", postfix);

    printf("Result: %d\n", evaluatePostfix(postfix));

    return 0;
}
