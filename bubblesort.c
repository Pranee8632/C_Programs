#include<stdio.h>
int main()
{
	int a[50],i,j,temp,size;
	printf("enter the size of an array:");
	scanf("%d",&size);
	printf("enter the elements in an array:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<size;i++)//for the passes--passes should be one less than the number of elements in an array
	{
		for(j=0;j<size-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("the elements after the sorting:");
	for(i=0;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
}
