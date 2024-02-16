/*Polynomial multiplication means : Each term of the polynomial must be multiplied with each term of the polynomial, 
multiplying each term means multiplying their coefficients and adding their exponents*/

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
	struct  node*temp=NULL;
	printf("Enter the number of terms in polynomial:");
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
		printf("Enter the power and coefficient:");
		scanf("%d",&temp->power);
		scanf("%d",&temp->coeff);
	}
	temp->next=NULL;
	return Head;
}

struct node* insert(struct node*head,int pow,int coeff)
{
	struct node*temp;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->power=pow;
	newnode->coeff=coeff;
	newnode->next=NULL;
	if(head==NULL || pow > head->power)
	{
		newnode->next=head;
		head=newnode;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL && temp->next->power >= pow)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
	return head;
}

void print(struct node*head)
{
	if(head==NULL)
	{
		printf("NO POLYNOMIAL");
	}
	else
	{
		struct node*tem=head;
		printf("The resultant multiplication polynomial is:\n");
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
}

void Pol_Mult(struct node*Head1,struct node*Head2)
{
	struct node*ptr1=Head1;
	struct node*ptr2=Head2;
	struct node*head=NULL;
	//Multiplication of the two polynomials
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			head=insert(head,ptr1->power + ptr2->power,ptr1->coeff * ptr2->coeff);
			ptr2=ptr2->next;
		}
		ptr1=ptr1->next;
		ptr2=Head2; 
		/*because we need to multiply each term of poly1 with all the terms of pol2
		after multiplying the first term of poly1 to all terms of poly2 the ptr2 becomes null ,so as the other 
		terms of the poly1 as to be multiplied with the terms poly2*/
	}
	printf("The result before simplification:");
	print(head);
	
	//To furthur simplify it
	struct node *ptr3=head;
	struct node *temp=NULL;
	while(ptr3->next!=NULL)
	{
		if(ptr3->power == ptr3->next->power)
		{
			ptr3->coeff=ptr3->coeff + ptr3->next->coeff;
			temp=ptr3->next;
			ptr3->next=ptr3->next->next;
			free(temp);
		}
		else
		{
			ptr3=ptr3->next;
		}
	}
	printf("\nAfter simplification:\n");
	print(head);
}



int main()
{
	struct node*head1=NULL;
	struct node*head2=NULL;
	printf("Enter the first polynomial:\n");
	head1=Create_Poly(head1);
	printf("Enter the second polynomial:\n");
	head2=Create_Poly(head2);
	Pol_Mult(head1,head2);
	return 0;
}


//struct node*Create_Poly(struct node*head)
//{
//	int n,i,coeff,power;
//	printf("Enter the number of terms in polynomial:");
//	scanf("%d",&n);
//	for(i=0;i<n;i++)
//	{
//		printf("Enter the power and coefficient:");
//		scanf("%d",&power);
//		scanf("%d",&coeff);
//		head=insert(head,power,coeff);
//	}
//	return head;
//}

