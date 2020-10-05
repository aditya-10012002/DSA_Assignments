#include<iostream>
#include<string>
using namespace std;

struct stack1 {
    int size;
    int top;
    char elements[50];
};
void push1(struct stack1 &S, char x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
char pop1(struct stack1 &S) {
    return (S.top == -1)?-1:S.elements[S.top--];
}
char peek1(struct stack1 &S) {
    return (S.top == -1)?-1:S.elements[S.top];
}
bool check_open(char ch) {
    return (ch == '(' || ch == '{' || ch == '[')?true:false;
}
bool check_close(char ch) {
    return (ch == ')' || ch == '}' || ch == ']')?true:false;
}
int index(char ch) {
    if(ch == '(' || ch == ')')
    return 0;
    else if(ch == '{' || ch == '}')
    return 1;
    else
    return 2;
}
bool check(string s) {
    struct stack1 S1;
    S1.size = 50;
    S1.top = -1;
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(check_open(s[i]))
        push1(S1, s[i]);
        if(check_close(s[i])) {
            if(index(s[i]) == index(peek1(S1)))
            pop1(S1);
            else
            return false;
        }
    }
    if(S1.top != -1)
    return false;
    return true;
}
int main() {
    cout << "Enter the brackets expression\n";
    string s;
    getline(cin, s);
    check(s)?cout << "Balanced\n":cout << "Not balanced\n";
    return 0;
}
