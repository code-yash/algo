#include <iostream>
using namespace std;
int heapsize=0,length=0;

void maxheapify(int A[],int i)
{
	int l=2*i+1;
	int r=2*(i+1);
	int max=i;
	if (l<heapsize && A[l]>A[max])
	max=l;
	
	if (r<heapsize && A[r]>A[max])
	max=r;
	
	if (i!=max)
	{
		int temp=A[i];
		A[i]=A[max];
		A[max]=temp;
		maxheapify(A,max);
	}
}

void buildheap(int A[])
{
	heapsize=length;
	for (int i=(length/2)-1;i>=0;i--)
	maxheapify(A,i);
}

void heapsort(int A[])
{
	buildheap(A);
	cout<<endl<<"INTERMEDIATE1"<<endl;
	  for(int k=0;k<length;k++)
		cout<<A[k]<<" ";
	for (int i=length-1;i>=1;i--)
	{
		int temp=A[heapsize-1];
		A[heapsize-1]=A[0];
		A[0]=temp;
		heapsize-=1;
		cout<<endl<<"INTERMEDIATE2"<<endl;
	  for(int k=0;k<length;k++)
		cout<<A[k]<<" ";
		maxheapify(A,0);
	}
}

int main()
{
	int A[]={3,6,1,8,9,4,0,2,10};
  length=9;

  heapsort(A);

  cout<<endl<<endl;
  for(int i=0;i<length;i++)
	cout<<A[i]<<" ";

  return 0;
}
