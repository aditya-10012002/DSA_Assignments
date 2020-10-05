#include<iostream>
#include<string>
using namespace std;

void brackets(string s, int open, int close, int n) {
  if(close == n)
  cout << s << endl;
  else {
    if(open > close)
    brackets(s+")", open, close+1, n);
    if(open < n)
    brackets(s+"(", open+1, close, n);
  }
}

int main() {
  cout << "Enter the number of brackets\n";
  int n;
  cin >> n;
  string s="";
  brackets(s, 0, 0, n);
  return 0;
}
