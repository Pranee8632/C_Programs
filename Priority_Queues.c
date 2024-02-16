#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	int priority;
	struct node*next;
};
struct node*head=NULL;

void insert(int val,int pri)
{
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->priority=pri;
	newnode->next=NULL;
	if(head==NULL || pri<head->priority)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		struct node*temp=head;
		while(temp->next!=NULL && temp->next->priority < pri)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}

void deletion()
{
	struct node*ptr=head;
	if(ptr==NULL)
	{
		printf("\nUnderflow");
	}
	else
	{
		printf("\nThe deleted element with priority %d is %d",head->priority,head->data);
		head=head->next;
		free(ptr);
	}
}

void display()
{
	struct node*temp=head;
	if(temp==NULL)
	{
		printf("\nEmpty");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("\nvalue=%d priority=%d ",temp->data,temp->priority);
			temp=temp->next;
		}
	}
}

int main()
{
	int choice;
	do{
		printf("\n\n.....MENU.......\n");
		printf("1.enqueue the element in queue\n");
		printf("2.dequeue the element from queue\n");
		printf("3.display the elements in queue \n");
		printf("4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			int y,z,val,priority;
			case 1:
				printf("Enter the value to enqueue:");
				scanf("%d",&val);
				printf("Enter the priority of the value:");
				scanf("%d",&priority);
				insert(val,priority);
				break;
					
			case 2:
				deletion();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				printf("Quitting");
				return 0;
					
			default:
				printf("Enter a valid choice\n");
		}
	}while(1);	
}
