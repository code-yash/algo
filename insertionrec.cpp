#include <iostream>
using namespace std;

void insertionsort(int A[],int n,int i)
{
	int j,temp;
	if (i<n)
	{
		j=i-1;
		temp=A[i];
		while (j>=0 && A[j]>temp)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=temp;
		insertionsort(A,n,i+1);
	}
}


int main()
{
	int n,i;
	cout<<"Enter Size:"<<endl;
	cin>>n;
	int A[n];
	cout<<"Array:"<<endl;
	for (i=0;i<n;i++)
	cin>>A[i];
	
	insertionsort(A,n,1);
	for (i=0;i<n;i++)
	cout<<A[i]<<" ";
	
}
