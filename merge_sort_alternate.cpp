#include<iostream>
using namespace std;

void mergearr(int arr[], int low, int mid, int high) {
  int n1 = mid-low+1;
  int n2 = high-mid;
  int arr1[high-low+1];
  for(int i=low;i<=mid;i++)
  arr1[i-low] = arr[i];
  for(int i=mid+1;i<=high;i++)
  arr1[i-low] = arr[i];
  int i=0, j=mid-low+1, k=low;
  while(i < n1 && j < high-low+1) {
    if(arr1[i] <= arr1[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr1[j++];
    }
  }
  while(i < n1)
  arr[k++] = arr1[i++];

  while(j < high-low+1)
  arr[k++] = arr1[j++];
}
void swap_arr(int arr[], int low, int high) {
  int arr1[high-low+1];
  int c=0;
  for(int i=low;i<=high;i+=2) {
    arr1[c++] = arr[i];
  }
  for(int i=low+1;i<=high;i+=2) {
    arr1[c++] = arr[i];
  }
  for(int i=low;i<=high;i++)
  arr[i] = arr1[i-low];
}
void mergesort(int arr[], int low, int high) {
  if(low < high) {
    swap_arr(arr, low, high);
    int mid = (low+high)/2;
    mergesort(arr, low, mid);
    mergesort(arr, mid+1, high);
    mergearr(arr, low, mid, high);
  }
}

int main() {
  cout << "Enter the array length\n";
  int n;
  cin >> n;
  int arr[n];
  cout << "Enter the array elements\n";
  for(int i=0;i<n;i++)
  cin >> arr[i];
  mergesort(arr, 0, n-1);
  cout << "Sorted array\n";
  for(int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
}
