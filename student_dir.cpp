#include<iostream>
using namespace std;

struct S {
  int rno;
  int tag;
  union {
    char cno[10];
    int hno;
  };
};

int main() {
  struct S std[5];
  cout << "Enter information for the 5 students\n";
  int n = 5;

  for(int i=0;i<n;i++) {
    cout << "Enter information for student " << i+1 << endl;
    cout << "Enter roll no.\n";
    cin >> std[i].rno;
    cout << "Enter address - 0 for c.no, 1 for h.no\n";
    cin >> std[i].tag;
    //std[i] -> union adr;
    if(std[i].tag == 0) {
      cout << "Enter the c.no less than 10 characters\n";
      cin >> std[i].cno;
    } else {
      cout << "Enter the h.no\n";
      cin >> std[i].hno;
    }
  }

  cout << "Student Information is as follows\n";

  for(int i=0;i<n;i++) {
    cout << "Information for student " << i+1 << endl;
    cout << "Roll no. " << std[i].rno << endl;
    if(std[i].tag == 0) {
      cout << "c.no is " << std[i].cno << endl;
    } else {
      cout << "h.no is " << std[i].hno << endl;
    }
  }
  return 0;
}
