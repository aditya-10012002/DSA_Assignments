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
void fill(stack &S1, int num) {
    if(S1.top == -1)
    push(S1, num);
    else {
        int n = pop(S1);
        fill(S1, num);
        push(S1, n);
    }
}
void reverse_stack(stack &S1) {
    if(S1.top != -1) {
        int num = pop(S1);
        reverse_stack(S1);
        fill(S1, num);
    }
}
int main() {
    int n;
    stack S1;
    S1.top = -1;
    S1.size = 50;
    for(int i=1;i<5;i++)
    push(S1, i);
    cout << "Initial: 4 3 2 1\n";
    reverse_stack(S1);
    cout << "Final: ";
    while(S1.top != -1)
    cout << pop(S1) << " ";
    cout << endl;
}
