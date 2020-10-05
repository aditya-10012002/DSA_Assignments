#include<iostream>
using namespace std;

union u {
  int num;
  char ch;
};

int main() {
  cout << "Enter the size of the array\n";
  int n;
  cin >> n;

  union u arr[n];
  int tag[n];
  int num_index = 0, ch_index = n-1;
  while(num_index <= ch_index) {
    cout << "Enter the tag for next element - 0 for int, 1 for char\n";
    int t;
    cin >> t;
    cout << "Enter the next element\n";
    if(t == 0) {
      cin >> arr[num_index].num;
      tag[num_index++] = t;
    } else {
      cin >> arr[ch_index].ch;
      tag[ch_index--] = t;
    }
  }

  cout << "Array filled\n";
  cout << "Output\n";
  for(int i=0;i<n;i++) {
    if(tag[i] == 0)
    cout << arr[i].num << " ";
    else
    cout << arr[i].ch << " ";
  }
  cout << endl;
  return 0;
}
