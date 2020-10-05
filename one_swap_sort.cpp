#include<iostream>
using namespace std;

void swap_sort(int arr[], int n) {
    bool flag1 = false;
    int i1 =-1;
    for(int i=0;i<n-1;i++) {
        if(!flag1 && arr[i+1] < arr[i]) {
            i1 = i;
            flag1 = true;
        } else if(flag1 && arr[i+1] < arr[i]) {
            swap(arr[i1], arr[i+1]);
            return;
        }
    }
    swap(arr[i1], arr[i1+1]);
}
int main() {
  cout << "Enter the array length\n";
  int n;
  cin >> n;
  int arr[n];
  cout << "Enter the array elements\n";
  for(int i=0;i<n;i++)
  cin >> arr[i];
  swap_sort(arr, n);
  cout << "Sorted array\n";
  for(int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
}
