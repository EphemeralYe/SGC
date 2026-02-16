#include<stdio.h>
#include<ctype.h>
#define MAX 100
typedef struct
{
	char items[MAX];
	int top;
}stack;
void initstack(stack *s)
{
	s->top=-1;
}
void push(stack*s,char c)
{
	s->items[++s->top]=c;
}
char  pop(stack *s)
{
	return s->items[s->top--];
}
char peek(stack *s)
{
	return s->items[s->top];
}
int precedence(char op)
{
	switch(op)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/':return 2;
		case '^':return 3;
	}
}
void infixtopostfix(char *infix,char *postfix)
{
	stack s;
	initstack(&s);
	int i,j=0;
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
		{
			postfix[j++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			push(&s,infix[i]);
		}
		else if(infix[i]==')') 
                {
                        while(peek(&s)!='(')
			{
				postfix[j++]=pop(&s);
			}
			pop(&s);
		}
		else
		{
			while(s.top !=-1 && precedence(peek(&s))>=precedence(infix[i]))
			{
				postfix[j++]=pop(&s);
			}
		}
	}
	while(s.top!=-1)
	{
		postfix[j++]=pop(&s);
	}
	postfix[j]='\0';
}
int main()
{
	char infix[MAX],postfix[MAX];
	printf("enter infix expression:");
	scanf("%s",infix);
	infixtopostfix(infix,postfix);
	printf("postfix expressions: %s\n",postfix);
	return 0;
}
