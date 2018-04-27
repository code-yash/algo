#include<iostream>
using namespace std;

int binary(int arr[],int num,int i,int j,int &k)
{ int first=0,last=j,mid;
  int pos=-2;
  while(first<=last && pos==-2)
  { mid=(first+last)/2;
    if(arr[i]<arr[first])
     { pos=first-1;
       k=first;
       }
    else if(arr[i]>arr[last])
     { pos=last+1;
       k=last;}
    else if(arr[i]>arr[mid])
     first=mid+1;
    else if(arr[i]<mid)
     last=mid-1;
   
  }
  return pos;
}       

void insert(int arr[],int i,int ins)
{ int temp,temp2;
  for(int j=0;j<=i;j++)
   if(j==ins)
   { temp=arr[j];//[1]=5
     arr[j]=arr[i];//[1]=5
   }
   else if(j>ins)
   { 
     temp2=arr[j];
     arr[j]=temp;
     temp=temp2;
   }
}     
       

void insertion(int arr[],int num)
{ for(int i=1;i<num;i++)
  { int j=i-1;
    int temp=arr[i],k;
    
    int pos=binary(arr,num,i,j,k);
    
    int ins;
    
    if(pos<k)//1<0
     ins=k;
    else
     ins=pos;
     
    insert(arr,i,ins);  
  }
}

int main()
{ int arr[]={3,5,2,7,1};
  int num=5;
  insertion(arr,num);
  
  for(int i=0;i<num;i++)
   cout<<arr[i]<<" ";
   
  return 0;
}       
