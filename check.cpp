#include<iostream>
using namespace std;
void shift(int A[],int key)
{
	if(key<=0)
	return;
	if(A[key-1]>A[key]) {
	swap(A[key-1], A[key]);
	}
  shift(A, key-1);
}

void insertion_recur(int A[],int n)
{
	if(n==0)
	return;

	insertion_recur(A,n-1);

	int key = n;
	shift(A,key);
}
int main()
{
	int i,n=5;
	int A[n];
	for(int i=0;i<n;i++)
	cin>>A[i];
	insertion_recur(A,n-1);
	for(i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<endl;
return 0;
}
