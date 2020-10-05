#include<iostream>
using namespace std;

int partition(int arr[], int low, int high, int p) {
  if(low > high) {
    swap(arr[p], arr[high]);
    return high;
  }
  if(arr[low] <= arr[p] && arr[high] >= arr[p])
  return partition(arr, low+1, high-1, p);
  else if(arr[low] <= arr[p])
  return partition(arr, low+1, high, p);
  else if(arr[high] >= arr[p])
  return partition(arr, low, high-1, p);
  else {
    swap(arr[low], arr[high]);
    return partition(arr, low, high, p);
  }
}
void quicksort(int arr[], int low, int high) {
  int k;
  if(low < high) {
    k = partition(arr, low+1, high, low);
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
