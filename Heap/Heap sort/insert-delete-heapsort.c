#include<stdio.h>
#include<stdlib.h>

void Insert(int A[],int n)
{
	int i = n;
	int temp;
	temp = A[i];
	while(i>1 && temp>A[i/2])
	{
		A[i] = A[i/2];
		i = i/2;
	}
	A[i] = temp;
}

void Delete(int A[], int n)
{
	int i,j,temp,x,val;
	val = A[1];
	x = A[n];
	A[1] = A[n];
	A[n] = val;
	i=1;
	j=2*i;
	while(j<=n-1)
	{
		if(j<n-1 && A[j]<A[j+1])
		{
			j = j+1;
		}
		if(A[j]>A[i])
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i = j;
			j = j*2;
		}
		else
		{
			break;
		}
	}
	return val;
}

int main()
{
	int H[] = {0,14,15,5,10,30,8,40};
	int i;
	for(i=2;i<=7;i++)
	{
		Insert(H,i);
	}
	
	for(i=7;i>=2;i--)
	{
		Delete(H,i);
	}
	
	for(i=1;i<=7;i++)
	{
		printf("%d ",H[i]);
	}
	return 0;
}
