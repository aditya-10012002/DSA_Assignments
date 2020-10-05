#include<iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int elements[50];
};
void push(struct stack &S, int x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
int pop(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top--];
}
int peek(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top];
}
bool isdigit(char ch) {
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
int main() {
    struct stack S1;
    S1.size = 50;
    S1.top = -1;
    string s;
    cout << "Enter the expression\n";
    getline(cin, s);
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(isdigit(s[i])) {
            int num = ((int)s[i++]-48);
            while(isdigit(s[i]) && i<n) {
                num = num*10 + ((int)s[i++]-48);
            }
            push(S1, num);
        } if(!isdigit(s[i]) && s[i] != ' ') {
            int n2 = pop(S1);
            int n1 = pop(S1);
            push(S1, eval(n1, n2, s[i]));
        }
    }
    cout << pop(S1) << endl;
    return 0;
}
