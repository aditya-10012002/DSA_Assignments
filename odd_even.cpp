#include<iostream>
//using namespace std;

void swap(int arr[], int f, int l) {
  int t = arr[f];
  arr[f] = arr[l];
  arr[l] = t;
}

int main() {
  int n;
  std::cout << "Enter the length of the array" << '\n';
  std::cin >> n;
  int arr[n];
  std::cout << "Enter the array elements" << '\n';
  for(int i=0;i<n;i++)
  std::cin >> arr[i];

  int f=0, l=n-1;
  while(f <= l) {
    if((arr[f]%2 != 0) && (arr[l]%2 == 0))
    swap(arr, f, l);
    else if(arr[f]%2 != 0)
    l--;
    else if(arr[l]%2 == 0)
    f++;
    else {
      f++;
      l--;
    }
  }
  std::cout << "Final array" << '\n';

  for(int i=0;i<n;i++)
  std::cout << arr[i] << ' ';
  std::cout << '\n';
  return 0;
}
