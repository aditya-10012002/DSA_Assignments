#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
  int p = arr[low];
  int l = low+1;
  int h = high;
  while(l < h) {
    while(arr[l] < p) l++;
    while(arr[h] > p) h--;
    if(l < h)
    swap(arr[l], arr[h]);
  }
  swap(arr[low], arr[h]);
  return h;
}
void quicksort(int arr[], int low, int high) {
  int k;
  if(low < high) {
    k = partition(arr, low, high);
    quicksort(arr, low, k-1);
    quicksort(arr, k+1, high);
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
  quicksort(arr, 0, n-1);
  cout << "Sorted array\n";
  for(int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
}
