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

void IMergeSort(int A[],int n)
{
	int i,l,h,p,mid;
	for(p=2;p<=n;p=p*2)
	{
		for(i=0;i+p-1<n;i=i+p)
		{
			l = i;
			h = i+p-1;
			mid = (l+h)/2;
			Merge(A,l,mid,h);
		}
	}
	if(p/2<n)
	{
		Merge(A,0,p/2-1,n);
	}
}

int main()
{
	int A[] = {2,10,18,4,6,8,32,1,14,12},n=10;
	IMergeSort(A,n);
	
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
