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
  for(int i=0;i<n;i++) {
    cout << "Enter the tag for " << i << " element - 0 for int, 1 for char\n";
    cin >> tag[i];
    cout << "Enter the " << i << " element\n";
    if(tag[i] == 0)
    cin >> arr[i].num;
    else
    cin >> arr[i].ch;
  }

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
