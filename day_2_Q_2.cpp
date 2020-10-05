#include<iostream>
using namespace std;

int main() {
  cout << "Enter the size of the array\n";
  int n;
  cin >> n;

  int arr[n];
  int num_index = 0, ch_index = n-1;
  while(num_index <= ch_index) {
    cout << "Enter the insertion tag for next element - 0 for front, 1 for rear\n";
    int t;
    cin >> t;
    cout << "Enter the next element\n";
    if(t == 0) {
      cin >> arr[num_index++];
    } else {
      cin >> arr[ch_index--];
    }
  }

  cout << "Array filled\n";
  cout << "Output\n";
  for(int i=0;i<n;i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
