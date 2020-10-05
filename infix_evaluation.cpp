#include<iostream>
#include<string>
using namespace std;

union U {
    int num;
    char ch;
};

struct single_stack {
    int size;
    int top;
    U elements[50];
};
void push(struct single_stack &S, U x) {
    if(S.top == S.size-1)
    cout << "single_stack is full\n";
    else
    S.elements[++S.top] = x;
}
U pop(struct single_stack &S, int tag) {
    if(S.top == -1) {
        U a;
        if(tag == 0)
        a.num = -1;
        else
        a.ch = 'a';
        return a;
    } else
    return S.elements[S.top--];
}
U peek(struct single_stack &S, int tag) {
    if(S.top == -1) {
        U a;
        if(tag == 0)
        a.num = -1;
        else
        a.ch = 'a';
        return a;
    } else
    return S.elements[S.top];
}
bool isDigit(char ch) {
    return (ch-48 >= 0 && ch-48 <= 9)?true:false;
}
int eval(int op1, int op2, char ch) {
    switch(ch) {
        case '+': return (op1+op2);
        case '-': return (op1-op2);
        case '/': return (op1/op2);
        case '*': return (op1*op2);
        case '%': return (op1%op2);
    }
    return -1;
}
int precedence(char ch) {
    switch(ch) {
        case '+': return 1;
        case '-': return 1;
        case '/': return 2;
        case '*': return 2;
        case '%': return 2;
    }
    return -1;
}
string toPostfix(string s) {
    struct single_stack S1;
    S1.top = -1;
    S1.size = 50;
    string str="";
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(isDigit(s[i])) {
            int num = s[i]-48;i++;
            while(isDigit(s[i]) && i<n) {
                num = num*10 + s[i++]-48;
            }
            str += to_string(num) + " ";
        }
        if(s[i] != ' ' && i<n) {
            U a;
            a.ch = s[i];
            if(S1.top == -1 || s[i] == '(' || precedence(s[i]) > precedence(peek(S1, 1).ch))
            push(S1, a);
            else if(s[i] == ')') {
                while(peek(S1, 1).ch != '(' && S1.top != -1)
                str += pop(S1, 1).ch;
                pop(S1, 1);
            } else if(precedence(s[i]) <= precedence(peek(S1, 1).ch)) {
                while(precedence(s[i]) <= precedence(peek(S1, 1).ch) && S1.top != -1) {
                    str += pop(S1, 1).ch;
                }
                push(S1, a);
            }
        }
    }
    while(S1.top != -1)
    str += pop(S1, 1).ch;
    return str;
}
void toValue(string s) {
    struct single_stack S1;
    S1.top = -1;
    S1.size = 50;
    int n = s.length();
    for(int i=0;i<n;i++) {
        U a;
        if(isDigit(s[i])) {
            int num = s[i]-48;i++;
            while(isDigit(s[i]) && i<n) {
                num = num*10 + s[i++]-48;
            }
            a.num = num;
            push(S1, a);
        }
        if(s[i] != ' ' && i<n) {
            int op2 = pop(S1, 0).num;
            int op1 = pop(S1, 0).num;
            a.num = eval(op1, op2, s[i]);
            push(S1, a);
        }
    }
    cout << pop(S1, 0).num << endl;
}
int main() {
    string s;
    cout << "Enter the infix expression\n";
    getline(cin, s);
    toValue(toPostfix(s));
    return 0;
}
