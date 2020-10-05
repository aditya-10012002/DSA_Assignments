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
void sort_stack(struct stack &S1, int n) {
    struct stack S2;
    S2.top = -1;
    S2.size = 50;
    int c = -1;
    while(c<n-1) {
        int max = 0;
        while(S1.top != c) {
            int num = pop(S1);
            max = (num > max)?num:max;
            push(S2, num);
        }
        bool flag = false;
        push(S1, max);
        while(S2.top != -1) {
            int num = pop(S2);
            if(num == max && !flag) {
                flag = true;
                continue;
            } else {
                push(S1, num);
            }
        }
        c++;
    }
    cout << "Sorted array using two stacks\n";
    while(S1.top != -1)
    cout << pop(S1) << " ";
    cout << endl;
}
int main() {
    struct stack S1;
    S1.top = -1;
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    S1.size = 50;
    for(int i=0;i<n;i++) {
        int num;
        cin >> num;
        push(S1, num);
    }
    sort_stack(S1, n);
    return 0;
}
