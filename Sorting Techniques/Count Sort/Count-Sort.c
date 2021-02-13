#include<stdio.h>
#include<stdlib.h>

int findMax(int A[],int n)
{
	int max = A[0];
	int i;
	for(i=1;i<n;i++)
	{
		if(A[i]>max)
		{
			max = A[i];
		}
	}
	return max;
}

void CountSort(int A[],int n)
{
	int max = findMax(A,n);
	int *B;
	B = (int *)malloc((max+1)*sizeof(int));
	int i;
	for(i=0;i<=max;i++)
	{
		B[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		B[A[i]]++;
	}
	int j=0;
	i=0;
	while(j<=max)
	{
		if(B[j]>0)
		{
			A[i++] = j;
			B[j]--;
		}
		else
		{
			j++;
		}
	}
}

int main()
{
	int A[] = {10,3,5,6,9,15,6,6,11,9},n=10;
	CountSort(A,n);
	
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	} 
	return 0;
}
