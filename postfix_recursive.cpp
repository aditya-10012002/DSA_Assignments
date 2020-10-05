#include<iostream>
#include<string>
using namespace std;

bool isDigit(char ch) {
    return ((int)ch >= 48 && (int)ch <= 57)?true:false;
}
int eval(int n1, int n2, char ch) {
    switch(ch) {
    case '+':
        return n1+n2;
    case '-':
        return n1-n2;
    case '*':
        return n1*n2;
    case '/':
        return (float)n1/n2;
    default:
        return -1;
    }
}
int arr[50];
int getValue(string s, int n, int index, int i) {
    if(index == n)
    return arr[i-1];
    else {
        if(isDigit(s[index])){
            int num = s[index]-48;index++;
            while(isDigit(s[index]) && index<n) {
                num = num*10 + ((int)s[index++]-48);
            }
            arr[i++] = num;
        }
        if(s[index] != ' ' && index<n) {
            arr[i-2] = eval(arr[i-2], arr[i-1], s[index]);
            i--;
        }
        return getValue(s, n, index+1, i);
    }
}
int main() {
    string s;
    cout << "Enter the postfix expression\n";
    getline(cin, s);
    cout << getValue(s, s.length(), 0, 0) << endl;
    return 0;
}
