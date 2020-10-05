#include<iostream>
using namespace std;

void mergearr(int arr[], int arr1[], int arr2[], int m, int n) {
  int i=0, j=0, k=0;
  while(i < m && j < n) {
    if(arr1[i] <= arr2[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }
  while(i < m)
  arr[k++] = arr1[i++];

  while(j < n)
  arr[k++] = arr2[j++];
}

int main() {
    int m, n, c=0;
    cout << "Enter the size of both arrays\n";
    cin >> m >> n;
    int arr3[m], arr1[m-n];
    int arr2[n];
    cout << "Enter the array elements of 1st array\n";
    for(int i=0;i<m;i++) {
        cin >> arr3[i];
        if(arr3[i] != 0)
        arr1[c++] = arr3[i];
    }
    cout << "Enter the array elements of 2nd array\n";
    for(int i=0;i<n;i++)
    cin >> arr2[i];
    int arr[m];
    mergearr(arr, arr1, arr2, m-n, n);

    cout << "Sorted array\n";
    for(int i=0;i<m;i++)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}
