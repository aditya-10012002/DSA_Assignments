#include<iostream>
using namespace std;

void insertionsort(int arr[], int n, int index) {
  if(index == 0 || index == n)
  return;
  if(arr[index] < arr[index-1]) {
    swap(arr[index], arr[index-1]);
    insertionsort(arr, n, index-1);
  }
  insertionsort(arr, n, index+1);
}
int main() {
  cout << "Enter length of array\n";
  int n;
  cin >>n;
  int arr[n];
  cout << "Enter the array elements\n";
  for(int i=0;i<n;i++)
  cin >> arr[i];
  insertionsort(arr, n, 1);
  cout << "Final array\n";
  for(int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
}
