#include<iostream>
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
int precedence(char ch) {
    if(ch == '+' || ch == '-')
    return 0;
    else if(ch == '*' || ch == '/')
    return 1;
    else
    return -1;
}
bool isDigit(char ch) {
    return (ch-48 >= 0 && ch-48 <= 9)?true:false;
}
int str_to_int(string s) {
    int num = 0;
    for(int i=0;i<s.length();i++)
    num = num*10 + s[i]-'0';
    return num;
}
string reverse(string s, int n) {
    s = "$" + s;n++;
    string str="";
    string temp="";
    for(int i=n-1;i>=0;i--) {
        if(s[i] == ' ')
        continue;
        else if(s[i] == '(')
        str += ')';
        else if(s[i] == ')')
        str += '(';
        else if(!isDigit(s[i])) {
            str += to_string(str_to_int(temp)) + s[i];
            temp="";
        } else {
            temp = s[i] + temp;
        }
    }
    if(str[str.length()-1] == '$')
    str = str.substr(0, str.length()-1);
    cout << str << endl;
    return str;
}

int main() {
    struct stack1 S1;
    S1.top = -1;
    S1.size = 50;
    string s, str="";
    cout << "Enter the infix expression\n";
    getline(cin, s);
    s = reverse(s, s.length());
    int n = s.length();
    for(int i=0;i<n;i++) {
        if(isDigit(s[i])) {
            int num = ((int)s[i++]-48);
            while(isDigit(s[i]) && i<n) {
                num = num*10 + ((int)s[i++]-48);
            }
            str += to_string(num) + " ";
        } if(s[i] != ' ' && i<n) {
            if(S1.top == -1)
            push1(S1, s[i]);
            else if(s[i] == ')') {
                while(peek1(S1) != '(' && S1.top != -1)
                str += pop1(S1);
                pop1(S1);
            }
            else if(s[i] == '(' || precedence(s[i]) > precedence(peek1(S1)))
            push1(S1, s[i]);
            else if(precedence(s[i]) <= precedence(peek1(S1))) {
                while(precedence(s[i]) <= precedence(peek1(S1)) && S1.top != -1)
                str += pop1(S1);
                push1(S1, s[i]);
            }
        }
    }
    while(S1.top != -1)
    str += pop1(S1);
    cout << str << endl;
    cout << reverse(str, str.length()) << endl;
}
