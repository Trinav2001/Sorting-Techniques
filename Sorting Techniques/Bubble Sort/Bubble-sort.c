#include<stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int A[], int n)
{
	int i,j,flag;
	for(i=0;i<n-1;i++)
	{
		flag = 0;
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				flag = 1;
			}
		}
		if(flag==0)
		{
			break;
		}
	}
}

int main()
{
	int A[] = {11,34,21,1,9,90,54,32,98,4},n=10,i;
	BubbleSort(A,n);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
