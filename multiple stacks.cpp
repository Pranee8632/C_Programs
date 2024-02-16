#include<stdio.h>
#include<string.h>
#define max 15
int top1=-1;
int top2=max;
int stack[max];

void push1(int stack[])
{
	int val;
	printf("Enter the value\n");
	scanf("%d",&val);
	if(top1==top2-1)
	{
		printf("stack owerflow\n");	
	}
	else  
	{
		top1++;
		stack[top1]=val;
	}
}

void push2(int stack[])
{
	int val;
	printf("Enter the value\n");
	scanf("%d",&val);
	if(top2-1==top1)
	{
		printf("stack owerflow\n");	
	}
	else
	{
		top2--;
		stack[top2]=val;
	}
}

int pop1(int stack[])
{
	int x;
	if(top1==-1)
	{
		printf("underflow \n");
	}
	else
	{
		x=stack[top1];
		top1--;
	}
	return x;
}

int pop2(int stack[])
{
	int x;
	if(top2==max)
	{
		printf("underflow \n");
	}
	else
	{
		x=stack[top2];
		top2++;
	}
	return x;
}

void display1(int stack[])
{
	if(top2==max)
	{
		printf("Underflow");
	}
	else
	{
		printf("display the element in stack 1\n");
		while(top1!=-1)
		{
			printf("%d\n",stack[top1]);
			top1--;
		}
	}
}

void display2(int stack[])
{
	if(top1==-1)
	{
		printf("Underflow");
	}
	else
	{
		printf("display the element in stack 2\n");
		while(top2!=max)
		{
			printf("%d\n",stack[top2]);
			top2++;
		}
	}
}

int main()
{
	int choice;
	do{
		printf("\n.....MENU.......\n");
		printf("1.push the element in stack 1\n");
		printf("2.push the element in stack 2\n");
		printf("3.pop the element from stack 1\n");
		printf("4.pop the element from stack 2\n");
		printf("5.Display the elements in the stack 1\n");
		printf("6.Display the elements in the stack 2\n");
		printf("7.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			int y,z;
			case 1:
				printf("\npush the element in stack 1\n");
				push1(stack);
				break;
				
			case 2:
				printf("push the element in stack 2\n");
				push2(stack);
				break;
					
			case 3:
				printf("pop the element in stack 1\n");
				y=pop1(stack);
				printf("the poped element is %d",y);
				break;
				
			case 4:
				printf("pop the element in stack 2\n");
				z=pop2(stack);
				printf("the poped element is %d",z);
				break;
				
			case 5:
				display1(stack);
				break;
				
			case 6:
				display2(stack);
				break;
				
			case 7:
				return 0;
					
			default:
				printf("Enter a valid choice\n");
		}
	}while(1);	
}
