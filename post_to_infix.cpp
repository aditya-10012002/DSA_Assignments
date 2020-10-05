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
int precedence(char ch) {
    if(ch == '+' || ch == '-')
    return 0;
    else if(ch == '*' || ch == '/' || ch == '%')
    return 1;
    else
    return -1;
}
bool check(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    for(int i=0;i<n1;i++) {
        if(!isDigit(s1[i]) && s1[i] != ' ')
        return true;
    }
    for(int i=0;i<n2;i++) {
        if(!isDigit(s2[i]) && s2[i] != ' ')
        return true;
    }
    return false;
}
int main() {
    struct stack2 S1;
    S1.top = -1;
    S1.size = 50;
    string s;
    cout << "Enter the postfix expression\n";
    getline(cin, s);
    int n = s.length();
    for(int i=0;i<n;i++) {
        string str="";
        if(isDigit(s[i])) {
            str += s[i++];
            while(isDigit(s[i]) && i<n)
            str += s[i++];
            push2(S1, str);
            str="";
        }
        if(s[i] != ' ' && i<n) {
            string s2 = pop2(S1);
            string s1 = pop2(S1);
            if(precedence(s[i]) > 0) {
                if(check(s1, s2))
                str = "(" + s1 + ")" + s[i] + "(" + s2 + ")";
                else
                str = s1 + s[i] + s2;
            } else
            str = s1 + s[i] + s2;
            push2(S1, str);
        }
    }
    cout << pop2(S1) << endl;
}
