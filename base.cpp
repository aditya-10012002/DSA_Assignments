#include<iostream>
using namespace std;

void convert(int n, int b) {
  if(n <= 0) cout << "";
  else {
    convert(n/b, b);
    if(b == 16 && n%b >= 10)
    cout << (char)(55 + n%b);
    else
    cout << (n%b);
  }
}
int main() {
  int n, b;
  cin >> n >> b;
  convert(n, b);
}
