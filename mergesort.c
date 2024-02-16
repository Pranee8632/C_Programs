#include<stdio.h>
void mergeSort(int arr[],int lb,int up);
void Merge(int arr[],int p,int q,int r);
void printArray(int arr[],int n);
int main()
{
	int a[9]={15,5,24,8,1,3,16,10,20};
	int size=sizeof(a)/sizeof(a[0]);
	mergeSort(a,0,size-1);
	printf("Sorted array:\n");
	printArray(a,size);
}
void mergeSort(int arr[],int lb,int up)//this is for the dividing
{
	if(lb<up)
	{
		int mid=(lb+up)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,up);
		Merge(arr,lb,mid,up);
	}
}
void Merge(int arr[],int p,int q,int r)
{
	int n1=q+1-p;
	int n2=r-q;
	int L[n1],R[n2],i,j,k;
	for(i=0;i<n1;i++)
	{
		L[i]=arr[p+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=arr[q+1+j];
	}
	i=0;j=0;k=p;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void printArray(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
