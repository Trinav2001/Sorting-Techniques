#include<iostream>
#include<math.h>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void Display(int A[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
}

int MaxElement(int A[],int n)
{
	int max = -32767;
	int i;
	for(i=0;i<n;i++)
	{
		if(A[i]>max)
		{
			max = A[i];
		}
	}
	return max;
}

int Digit(int max)
{
	int x = max,count=0;
	while(x!=0)
	{
		x = x/10;
		count++;
	}
	return count;
}

int index(int x,int idx)
{
	return (int)((x/(10^idx))%10);
}

void Initializebins(Node **bins,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		bins[i] = NULL;
	}
}

void Insert(Node **p,int x,int index)
{
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	if(p[index]==NULL)
	{
		p[index] = temp;
	}
	else
	{
		Node *q = p[index];
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q->next = temp;
	}
}

int Delete(Node **bins,int index)
{
	Node *p=bins[index];
	bins[index] = bins[index]->next;
	int x = p->data;
	delete p;
	return x;
}

void RadixSort(int A[],int n)
{
	int max = MaxElement(A,n);
	int nPass = Digit(max);
	Node **bins = new Node*[10];
	Initializebins(bins,10);
	int pass,idx,i,j;
	for(pass=0;pass<nPass;pass++)
	{
		for(i=0;i<n;i++)
		{
			int k = pow(10,pass);
			idx = ((A[i]/k)%10);
			Insert(bins,A[i],idx);
		}
		i = 0;
		j = 0;
		while(i<n)
		{
			while(bins[i]!=NULL)
			{
				A[j++] = Delete(bins,i);
			}
			i++;
		}
		Initializebins(bins,10);
	}
	
	delete []bins;
}

int main()
{
	int A[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
	int n = sizeof(A)/sizeof(A[0]);
	RadixSort(A,n);
	Display(A,n);
	return 0;
}
