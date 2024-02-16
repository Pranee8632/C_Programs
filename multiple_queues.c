#include<stdio.h>
#define max 10
int front1=-1,rear1=-1,front2=max,rear2=max;
int queue[max];
void enqueue1(int val)
{
	if(rear1==rear2-1)
	{
		printf("\n overflow");
	}
	else
	{
		if(front1==-1 && rear1==-1)
		{
			front1=rear1=0;
			queue[front1]=val;
		}
		else
		{
			rear1++;
			queue[rear1]=val;
		}
	}
}
void enqueue2(int val)
{
	if(rear2-1==rear1)
	{
		printf("\noverflow");
	}
	else
	{
		if(front2==max && rear2==max)
		{
			front2=rear2=max-1;
			queue[front2]=val;
		}
		else
		{
			rear2--;
			queue[rear2]=val;
		}
	}
}
int dequeue1()
{
	int x;
	if(front1==-1)
	{
		printf("\n underflow");
	}
	else
	{
		x=queue[front1];
		front1++;
		if(front1>rear1)
		{
			front1=rear1=-1;
		}
		return x;
	}
}

int dequeue2()
{
	int x;
	if(front2==max)
	{
		printf("\n underflow");
	}
	else
	{
		x=queue[front2];
		front2--;
		if(front2<rear2)
		{
			front2=rear2=max;
		}
		return x;
	}
}

void display1()
{
	if(front1==-1)
	{
		printf("\n queue is empty");
	}
	else
	{
		int i;
		for(i=front1;i<=rear1;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}

void display2()
{
	if(front2==max)
	{
		printf("\n queue is empty");
	}
	else
	{
		int i;
		for(i=front2;i>=rear2;i--)
		{
			printf("%d\t",queue[i]);
		}
	}
}
int main()
{
	int choice;
	do{
		printf("\n.....MENU.......\n");
		printf("1.enqueue the element in queue1\n");
		printf("2.enqueue the element in queue2\n");
		printf("3.dequeue the element from queue 1\n");
		printf("4.dequeue the element from queue 2\n");
		printf("5.Display the elements in the queue 1\n");
		printf("6.Display the elements in the queue 2\n");
		printf("7.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			int y,z,val;
			case 1:
				printf("Enter the value to enqueue:");
				scanf("%d",&val);
				enqueue1(val);
				break;
				
			case 2:
				printf("Enter the value to enqueue:");
				scanf("%d",&val);
				enqueue2(val);
				break;
					
			case 3:
				y=dequeue1();
				printf("the dequeued element is %d",y);
				break;
				
			case 4:
				z=dequeue2();
				printf("the dequeued element is %d",z);
				break;
				
			case 5:
				display1();
				break;
				
			case 6:
				display2();
				break;
				
			case 7:
				printf("Quitting");
				return 0;
					
			default:
				printf("Enter a valid choice\n");
		}
	}while(1);	
}
