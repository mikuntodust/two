#include<stdio.h>
typedef int DataType;
int Reverse(DataType A[],int left,int right,int arraySize)
{
	if(left>=right||right>=arraySize) return false;
	int mid=(left+right)/2;
	for(int i=0;i<=mid-left;i++)
	{
		DataType temp;
		temp=A[left+i];
		A[left+i]=A[right-i];
		A[right-i]=temp;
	}
}
void Exchange(DataType A[],int m,int n,int arraySize)
{
	Reverse(A,0,m+n-1,arraySize);
	Reverse(A,0,n-1,arraySize);
	Reverse(A,n,m+n-1,arraySize);
}
int main()
{
	DataType A[10]={1,2,3,4,5,6,7,-1,-2,-3};
	int i=0;
	for(i=0;i<10;i++) printf("%d\t",A[i]);
	int m=7,n=3,arraySize=10;
	printf("\n");
	Exchange(A,m,n,arraySize);
	for(i=0;i<10;i++) printf("%d\t",A[i]);
}
