#include <iostream>
using namespace std;
void countsort(int A[],int k)
{
	int B[20];
	int i,j;
	int C[k+1];//0 to 3 so 4
	
	for(i=0;i<=k;i++)
	C[i]=0;
	
	for (j=0;j<13;j++)
	C[A[j]]=C[A[j]]+1;
	
	for (i=1;i<=k;i++)
	C[i]=C[i]+C[i-1];
	
	for (j=0;j<13;j++)
	{
		B[C[A[j]]-1]=A[j];
		C[A[j]]=C[A[j]]-1;
	}
	
	for (i=0;i<13;i++)
	cout<<B[i]<<" ";
}

int main()
{
	int A[]={0,1,2,0,3,0,3,2,3,3,0,1,1};
	int k=3;
	countsort(A,k);
	return 0;
}
