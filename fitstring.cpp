/*Suppose instead of powers of two, we represent integers as the sum of Fibonacci numbers. In other
words, instead of an array of bits, we keep an array of fits, where the ith least significant fit
indicates whether the sum includes the ith Fibonacci number Fi .
For example, the fitstring (101110)F represents the number F6 + F4 + F3 + F2 = 8+3+2+1 = 14.
Write functions to increment and decrement a single fitstring.
[Hint: Most numbers can be represented by more than one fitstring!] */

#include<iostream>
#include<string>
using namespace std;

void change(int arr[], int num, int n) {
  string s="";
  bool flag = false;
  for(int i=n-1;i>=0;i--) {
    if(arr[i] <= num) {
      flag = true;
      num -= arr[i];
      s += "1";
    } else {
      if(flag)
      s += "0";
    }
  }
  cout << s << endl;
}
void fib(int arr[], int n) {
  for(int i=2;i<n;i++)
  arr[i] = arr[i-1] + arr[i-2];
}

int main() {
  string s;
  cin >> s;
  int n = s.length();
  int arr[n+1];
  arr[0] = 1;
  arr[1] = 1;
  fib(arr, n+1);
  int num = 0;
  for(int i=0;i<n;i++) {
    num += arr[n-i-1]*((int)(s[i])-48);
  }
  change(arr, num+1, n+1);
  change(arr, num-1, n);
}
