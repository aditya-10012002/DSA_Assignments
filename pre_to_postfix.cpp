#include<iostream>
using namespace std;

struct stack2 {
    int size;
    int top;
    string elements[50];
};
void push2(struct stack2 &S, string x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
string pop2(struct stack2 &S) {
    return (S.top == -1)?"-1":S.elements[S.top--];
}
string peek2(struct stack2 &S) {
    return (S.top == -1)?"-1":S.elements[S.top];
}
bool isDigit(char ch) {
    return (ch-48 >= 0 && ch-48 <= 9)?true:false;
}
int main() {
    struct stack2 S1;
    S1.top = -1;
    S1.size = 50;
    string s;
    cout << "Enter the prefix expression\n";
    getline(cin, s);
    int n = s.length();
    for(int i=n-1;i>=0;i--) {
        string str="";
        if(isDigit(s[i])) {
            str = s[i--] + str;
            while(isDigit(s[i]) && i>=0)
            str = s[i--] + str;
            push2(S1, str);
            str="";
        }
        if(s[i] != ' ' && i>=0) {
            string s1 = pop2(S1);
            string s2 = pop2(S1);
            str = s1+" "+s2+s[i];
            push2(S1, str);
        }
    }
    cout << pop2(S1) << endl;
}
