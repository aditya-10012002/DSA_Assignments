#include<iostream>
using namespace std;

void mergearr(int arr[], int low, int mid, int high) {
  int n1 = mid-low+1;
  int n2 = high-mid;
  int arr1[n1];
  int arr2[n2];
  for(int i=low;i<=mid;i++)
  arr1[i-low] = arr[i];
  for(int i=mid+1;i<=high;i++)
  arr2[i-mid-1] = arr[i];
  int i=0, j=0, k=low;
  while(i < n1 && j < n2) {
    if(arr1[i] <= arr2[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }
  while(i < n1)
  arr[k++] = arr1[i++];

  while(j < n2)
  arr[k++] = arr2[j++];
}
void mergesort(int arr[], int low, int high) {
  if(low < high) {
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
