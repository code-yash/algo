#include <iostream>
using namespace std;
void insertionsort(int A[],int n)
{
	int c=0,s=0;
	int temp,h,i;
	for (i=1;i<n;i++)
	{
		temp=A[i];
		h=i-1;
		while (h>=0 && A[h]>temp)
		{
			A[h+1]=A[h];
			h--;
		}
		A[h+1]=temp;
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
	
	insertionsort(A,n);
	for (i=0;i<n;i++)
	cout<<A[i]<<" ";
	
}
