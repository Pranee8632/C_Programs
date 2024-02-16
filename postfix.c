#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct
{
	int data[MAXSIZE];
	int top;
}Stack;

void initialize(Stack*s)
{
	s->top=-1;
}

int isFull(Stack*s)
{
	return s->top == MAXSIZE-1;
}

int isEmpty(Stack*s)
{
	return s->top == -1;
}

void push(Stack*s,int value)
{
	if(isFull(s))
	{
		printf("Stack Overflow!\n");
		exit(1);
	}
	s->data[++s->top]=value;
}

int pop(Stack*s)
{
	if(isEmpty(s))
	{
		printf("Stack Underflow!\n");
		exit(1);
	}
	return s->data[s->top--];
}

int peek(Stack*s)
{
	if(isEmpty(s))
	{
		printf("Stack is Empty!\n");
		exit(1);
	}
	return s->data[s->top];
}

int priority(char op)
{
	if(op=='+' || op=='-')
		return 1;
	else if(op=='*' || op=='/')
		return 2;
	return 0;
}

void InfixToPostfix(char *infix, char *postfix)
{
	Stack OperatorStack;
	initialize(&OperatorStack);
	int i,j=0;
	for(i=0;infix[i]!='\0';++i)
	{
		char c=infix[i];
		if(isalnum(c))
		{
			postfix[j++]=c;
		}
		else if(c=='(')
		{
			push(&OperatorStack,c);
		}
		else if(c==')')
		{
			while(!isEmpty(&OperatorStack) && peek(&OperatorStack)!='(')
			{
				postfix[j++]=pop(&OperatorStack);
			}
			pop(&OperatorStack);
		}
		else
		{
			while(!isEmpty(&OperatorStack) && priority(c) <=priority(peek(&OperatorStack)))
			{
				postfix[j++]=pop(&OperatorStack);
			}
			push(&OperatorStack,c);
		}
			
	}
	while(!isEmpty(&OperatorStack))
	{
		postfix[j++]=pop(&OperatorStack);
	}
	postfix[j]='\0';
}

int EvaluatePostfix(char *postfix)
{
	Stack OperandStack;
	initialize(&OperandStack);
	int i;
	for(i=0;postfix[i]!='\0';++i)
	{
		char c=postfix[i];
		if(isdigit(c))
		{
			push(&OperandStack,c-'0');
		}
		else
		{
			int oper2=pop(&OperandStack);
			int oper1=pop(&OperandStack);
			switch(c)
			{
				case '+':
					push(&OperandStack,oper1+oper2);
					break;
				case '-':
					push(&OperandStack,oper1-oper2);
					break;
				case '*':
					push(&OperandStack,oper1*oper2);
					break;
				case '/':
					push(&OperandStack,oper1/oper2);
					break;
			}
		}
	}
	return peek(&OperandStack);
}

int main()
{
	char infix[MAXSIZE];
	printf("Enter the Infix Expression:");
	fgets(infix,sizeof(infix),stdin);
	infix[strlen(infix)-1]='\0';
	char postfix[MAXSIZE];
	InfixToPostfix(infix,postfix);
	printf("Postfix Expression :%s\n",postfix);
	int result=EvaluatePostfix(postfix);
	printf("Ans after Evaluating:%d\n",result);
	
	return 0;
}
						
			
			
			
			
			

