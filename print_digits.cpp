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
int main() {
    struct stack S1;
    S1.size = 50;
    S1.top = -1;
    int n;
    cout << "Enter the number\n";
    cin >> n;
    while(n != 0) {
        push(S1, n%10);
        n /= 10;
    }
    while(S1.top != -1)
    cout << pop(S1);
    cout << endl;
    return 0;
}
