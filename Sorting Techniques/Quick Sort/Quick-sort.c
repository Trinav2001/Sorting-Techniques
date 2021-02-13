#include<stdio.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int A[],int l,int h)
{
	int i=l,j=h;
	int pivot = A[l]; 
	do
	{
		do{
			i++;
		}while(A[i]<=pivot);
		do{
			j--;
		}while(A[j]>pivot);
		if(i<j)
		{
			swap(&A[i],&A[j]);
		}
	}while(i<j);
	swap(&A[l],&A[j]);
	return j;
}

void QuickSort(int A[],int l,int h)
{
	int j;
	if(l<h)
	{
		j = Partition(A,l,h);
		QuickSort(A,l,j);
		QuickSort(A,j+1,h);
	}
}

int main()
{
	int A[] = {11,34,9,2,100,36,21,28,99,50,32676}, n = 11,i;
	
	QuickSort(A,0,n-1);
	
	for(i=0;i<n-1;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
