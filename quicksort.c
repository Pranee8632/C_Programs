#include<stdio.h>
void QuickSort(int arr[],int lb,int ub)
{	
	int loc;
	if(lb<ub)
	{
		loc=partition(arr,lb,ub);
		QuickSort(arr,lb,loc-1);
		QuickSort(arr,loc+1,ub);
	}
}
int partition(int a[],int lb,int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[lb],&a[end]);
	return end;
}
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[]={8,7,2,1,0,9,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("The unsorted array:\n");
	printArray(arr,n);
	QuickSort(arr,0,n-1);
	printf("the sorted array:\n");
	printArray(arr,n);
}
