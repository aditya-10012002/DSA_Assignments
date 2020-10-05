#include<iostream>
using namespace std;

void print(int arr[], int index) {
  for(int i=0;i<index;i++)
  cout << arr[i] << " ";
  cout << endl;
}
void rec_sum(int n, int arr[], int index) {
  if(n == 0)
  print(arr, index);
  else {
    for(int i=0;i<n;i++) {
      arr[index] = n-i;
      if(index > 0 && arr[index] > arr[index-1])
      continue;
      rec_sum(i, arr, index+1);
    }
  }
}
int main() {
  int n;
  cin >> n;
  int arr[n];
  rec_sum(n, arr, 0);
  return 0;
}
