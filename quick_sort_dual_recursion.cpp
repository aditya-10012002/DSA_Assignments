#include<iostream>
using namespace std;

int partition1(int arr[], int low, int high, int p) {
  if(low > high) {
    swap(arr[p], arr[high]);
    return high;
  }
  if(arr[low] <= arr[p] && arr[high] >= arr[p])
  return partition1(arr, low+1, high-1, p);
  else if(arr[low] <= arr[p])
  return partition1(arr, low+1, high, p);
  else if(arr[high] >= arr[p])
  return partition1(arr, low, high-1, p);
  else {
    swap(arr[low], arr[high]);
    return partition1(arr, low, high, p);
  }
}

int partition2(int arr[], int low, int high, int p) {
  if(low > high) {
    swap(arr[p], arr[low]);
    return low;
  }
  if(arr[low] <= arr[p] && arr[high] >= arr[p])
  return partition2(arr, low+1, high-1, p);
  else if(arr[low] <= arr[p])
  return partition2(arr, low+1, high, p);
  else if(arr[high] >= arr[p])
  return partition2(arr, low, high-1, p);
  else {
    swap(arr[low], arr[high]);
    return partition2(arr, low, high, p);
  }
}

void insertion_dual(int arr[], int low, int high) {
  if(low < high) {
    int k1 = partition1(arr, low+1, high, low);
    int k2 = partition2(arr, low, high-1, high);
    insertion_dual(arr, low, k1-1);
    insertion_dual(arr, k1+1, k2-1);
    insertion_dual(arr, k2+1, high);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)
  cin >> arr[i];
  insertion_dual(arr, 0, n-1);
  for(int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
}
