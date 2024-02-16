//Polynomial addition
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int power;
	int coeff;
	struct node *next;
};

struct node *Create_Poly(struct node *Head)
{	
	int n,i;
	struct node*temp=NULL;
	printf("Number of terms in the polynomial:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		if(Head==NULL)
		{
			Head=(struct node*)malloc(sizeof(struct node));
			temp=Head;
		}
		else
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
		}
		printf("enter the power and coefficient:\n");
		scanf("%d",&temp->power);
		scanf("%d",&temp->coeff);
	}
	temp->next=NULL;
	return Head;
}

void Add_Pol(struct node*Pol1,struct node*Pol2)
{
	struct node*Add=NULL,*temp=NULL;
	while(Pol1!=NULL && Pol2!=NULL)
	{
		if(temp==NULL)
		{
			temp=(struct node*)malloc(sizeof(struct node));
			temp->next=NULL;
			Add=temp;
		}
		else
		{
			temp->next=(struct node*)malloc(sizeof(struct node));
			temp=temp->next;
			temp->next=NULL;
		}
		if(Pol1->power>Pol2->power)
		{
			temp->power=Pol1->power;
			temp->coeff=Pol1->coeff;
			Pol1=Pol1->next;
		}
		else if(Pol1->power==Pol2->power)
		{
			temp->power=Pol1->power;
			temp->coeff=Pol1->coeff+Pol2->coeff;
			Pol1=Pol1->next;
			Pol2=Pol2->next;
		}
		else
		{
			temp->power=Pol2->power;
			temp->coeff=Pol2->coeff;
			Pol2=Pol2->next;
		}
	}
	while(Pol1!=NULL)
	{
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		temp->next=NULL;
		temp->power=Pol1->power;
		temp->coeff=Pol1->coeff;
		Pol1=Pol1->next;
	}
	while(Pol2!=NULL)
	{
		temp->next=(struct node*)malloc(sizeof(struct node));
		temp=temp->next;
		temp->next=NULL;
		temp->power=Pol2->power;
		temp->coeff=Pol2->coeff;
		Pol2=Pol2->next;
	}
	print(Add);
}

void print(struct node*Add)
{
	struct node*tem=Add;
	printf("The resultant addition polynomial is:\n");
	while(tem!=NULL)
	{
		printf("%dX^%d",tem->coeff,tem->power);
		tem=tem->next;
		if(tem!=NULL)
		{
			printf("+");
		}
	}
}

int main()
{
	struct node*Head1=NULL,*Head2=NULL;
	printf("Enter the first polynomial:\n");
	Head1=Create_Poly(Head1);
	printf("Enter the second polynomial:\n");
	Head2=Create_Poly(Head2);
	Add_Pol(Head1,Head2);
}

