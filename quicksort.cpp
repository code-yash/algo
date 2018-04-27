#include <iostream>
using namespace std;

int partition(int arr[],int p,int r)
{
	int temp;
	int x=arr[r];
	int i=p-1;
	for (int j=p;j<=r-1;j++)
	{
		if (arr[j]<x)
		{
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	return i+1;
}

void quicksort(int arr[],int p,int r)
{
	int q;
	if (p<r)
	{
		q=partition(arr,p,r);
		quicksort(arr,p,q-1);
		quicksort(arr,q+1,r);
	}
}

int main()
{
	int arr[]={5,2,8,1,11,7,4};
	int r=6,p=0;
	quicksort(arr,p,r);
	for (int i=0;i<7;i++)
	cout << arr[i] << " ";
	
	return 0;
}
