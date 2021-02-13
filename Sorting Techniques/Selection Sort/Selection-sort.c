#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void SelectionSort(int A[], int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		for(j=k=i;j<n;j++)
		{
			if(A[j]<A[k])
			{
				k = j;
			}
		}
		swap(&A[i],&A[k]);
	}
}

int main()
{
	int A[] = {11,34,21,1,9,90,54,32,98,4},n=10,i;
	SelectionSort(A,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
