#include<iostream>
#include<stdlib.h>
using namespace std;

int partition(int arr[],int p,int r)
{
  int x=arr[r];
  int i=p-1;
  for(int j=p;j<=r-1;j++)
	if(x>=arr[j])
	 { i=i+1;
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	  }
  int tem=arr[i+1];
  arr[i+1]=arr[r];
  arr[r]=tem;
  return i+1;
}

int randomPart(int arr[],int p,int r)
{ int f=r-p;
  int x=(random()%100)%f+p;
  //cout<<endl<<x;
  int temp=arr[x];
  arr[x]=arr[r];
  arr[r]=temp;
  partition(arr,p,r);
}


void quicksort(int arr[],int p,int r)
{ if(p<r)
  { int q=randomPart(arr,p,r);
	 quicksort(arr,p,q-1);
	 quicksort(arr,q+1,r);
	}
}

int main()
{ /*cout<<endl<<rand()%100<<endl;
  int f=10-6;
  int x=(random()%100)%f;
  cout<<x<<endl; 
  x=(random()%100)%f;
  cout<<x<<endl; 
  */int arr[]={3,6,1,8,2,10,4,7,0,12,15,9,14,5};
  int r=13;
//  for(int i=0;i<=r;i++)
//	cout<<arr[i]<<" ";
  
  quicksort(arr,0,r);
  cout<<endl<<endl;
  for(int i=0;i<=r;i++)
	cout<<arr[i]<<" ";
  return 0;
}
