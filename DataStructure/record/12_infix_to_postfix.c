#include <stdio.h>
#include <ctype.h>

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
    switch (op) 
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

void infixToPostfix(char *infix, char *postfix) 
{
    Stack s;
    initStack(&s);
    int i, j = 0;

    // Fixed: Removed space from null terminator check
    for (i = 0; infix[i] != '\0'; i++) 
    {
        if (isalnum(infix[i])) 
        {
            postfix[j++] = infix[i];
        } 
        else if (infix[i] == '(') 
        {
            push(&s, infix[i]);
        } 
        else if (infix[i] == ')') 
        {
            while (s.top != -1 && peek(&s) != '(') 
            {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } 
        else // Operator encountered
        {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i])) 
            {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (s.top != -1) 
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0'; // Fixed: Removed space from null terminator
}

int main() 
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
