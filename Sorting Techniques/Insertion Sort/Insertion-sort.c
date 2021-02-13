#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(int A[], int n)
{
	int x,i,j;
	for(i=1;i<n;i++)
	{
		j = i-1;
		x = A[i];
		while(j>-1 && A[j]>x)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
}

int main()
{
	int A[] = {11,34,21,1,9,90,54,32,98,4},n=10,i;
	InsertionSort(A,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
