#include<iostream>
using namespace std;

string reverse(string s, int n) {
    string str="";
    for(int i=n-1;i>=0;i--)
    str += (s[i] == '(')?')':'(';
    return str;
}
int balance(string s) {
    int b_o = 0, c = 0, t = 2;
    int n = s.length();
    while(t-- > 0) {
        b_o = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '(')
            b_o++;
            else {
                if(b_o <= 0) {
                    s[i] = '(';
                    c++;
                    b_o++;
                }
                else
                b_o--;
            }
        }
        s = reverse(s, n);
    }
    return (b_o == 0)?c:-1;
}
int main() {
    string s;
    cout << "Enter the unbalanced brackets expression\n";
    getline(cin, s);
    int c = balance(s);
    if( c == -1)
    cout << "Not possible" << endl;
    else
    cout << c << endl;
    return 0;
}
