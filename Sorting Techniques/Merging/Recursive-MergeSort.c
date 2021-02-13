#include<stdio.h>
#include<stdlib.h>

void Merge(int A[],int l,int mid,int h)
{
	int m = h+1;
	int B[m];
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=h)
	{
		if(A[i]<A[j])
		{
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}
	
	for(;i<=mid;i++)
	{
		B[k++] = A[i];
	}
	for(;j<=h;j++)
	{
		B[k++] = A[j];
	}
	for(i=l;i<=h;i++)
	{
		A[i] = B[i];
	}
}

void RMergeSort(int A[],int l,int h)
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
		RMergeSort(A,l,mid);
		RMergeSort(A,mid+1,h);
		Merge(A,l,mid,h);
	}
}

int main()
{
	int A[] = {2,10,18,4,6,8,32,1,14,12},n=10;
	RMergeSort(A,0,n-1);
	
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
