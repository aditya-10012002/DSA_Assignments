#include<iostream>
#include<string>
using namespace std;

bool isDigit(char ch) {
    return ((int)ch >= 48 && (int)ch <= 57)?true:false;
}
string arr1[50];
string getString(string s, int n, int index, int i) {
    if(index == n)
    return arr1[i-1];
    else {
        if(isDigit(s[index])){
            int num = s[index]-48;index++;
            while(isDigit(s[index]) && index<n) {
                num = num*10 + ((int)s[index++]-48);
            }
            arr1[i++] = to_string(num);
        }
        if(s[index] != ' ' && index<n) {
            arr1[i-2] = s[index] + arr1[i-2] + " " + arr1[i-1];
            i--;
        }
        return getString(s, n, index+1, i);
    }
}
int main() {
    string s;
    cout << "Enter the postfix expression\n";
    getline(cin, s);
    cout << getString(s, s.length(), 0, 0) << endl;
    return 0;
}
