#include<iostream>
using namespace std;

struct ll {
  int data;
  struct ll *next;
};

int main() {
  struct ll L1;
  //L1 = new(ll);
  L1.data = 1;

  struct ll L2;
  //L2 = new(ll);
  L2.data = 2;
  L1.next = &L2;
  cout << L1.data << " " << L2.data << endl;
  cout << L1.next -> data << endl;
  cout << L1.next -> next << endl;
  return 0;
}
