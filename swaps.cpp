#include<iostream>
using namespace std;

void swap1(int x, int y) {
  int t;
  t = x;
  x = y;
  y = t;
  cout << x << " " << y << endl;
}
void swap2(int &x, int &y) {
  int t;
  t = x;
  x = y;
  y = t;
  cout << x << " " << y << endl;
}
void swap3(int *x, int *y) {
  int t;
  t = *x;
  *x = *y;
  *y = t;
  cout << *x << " " << *y << endl;
}
void swap4(int x, int *y) {
  int t;
  t = x;
  x = *y;
  *y = t;
  cout << x << " " << *y << endl;
}
void swap5(int *x, int y) {
  int t;
  t = *x;
  *x = y;
  y = t;
  cout << *x << " " << y << endl;
}
void swap6(int x, int &y) {
  int t;
  t = x;
  x = y;
  y = t;
  cout << x << " " << y << endl;
}
void swap7(int &x, int y) {
  int t;
  t = x;
  x = y;
  y = t;
  cout << x << " " << y << endl;
}
void swap8(int *x, int &y) {
  int t;
  t = *x;
  *x = y;
  y = t;
  cout << *x << " " << y << endl;
}
void swap9(int &x, int *y) {
  int t;
  t = x;
  x = *y;
  *y = t;
  cout << x << " " << *y << endl;
}
int main() {
  int a, b;
  cout<< "Enter the two numbers to be swapped\n";
  cin >> a >> b;
  //swap1(a, b);
  //swap2(a, b);
  //swap3(&a, &b);
  //swap4(a, &b);
  //swap5(&a, b);
  //swap6(a, b);
  //swap7(a, b);
  //swap8(&a, b);
  //swap9(a, &b);
  cout << a << " " << b << endl;
  return 0;
}
