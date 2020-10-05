#include<iostream>
using namespace std;

struct two_stack {
    int size;
    int top1;
    int top2;
    int elements[100];
};
void push_1(struct two_stack &S, int x) {
    if(S.top1 == S.top2-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top1] = x;
}
int pop_1(struct two_stack &S) {
    return (S.top1 == -1)?-1:S.elements[S.top1--];
}
int peek_1(struct two_stack &S) {
    return (S.top1 == -1)?-1:S.elements[S.top1];
}
void push_2(struct two_stack &S, int x) {
    if(S.top2 == S.top1+1)
    cout << "Stack is full\n";
    else
    S.elements[--S.top2] = x;
}
int pop_2(struct two_stack &S) {
    return (S.top2 == 100)?-1:S.elements[S.top2++];
}
int peek_2(struct two_stack &S) {
    return (S.top2 == 100)?-1:S.elements[S.top2];
}
int main() {
    struct two_stack S1;
    S1.size = 100;
    S1.top1 = -1;
    S1.top2 = 100;
    while (true) {
        cout << "Enter 1 to push in stack1, 2 to pop in stack 1, 3 to peek in stack 1\n";
        cout << "Enter 4 to push in stack2, 5 to pop in stack 2, 6 to peek in stack 2\n";
        cout << "Enter 0 to break out\n";
        int ch;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                cout << "Enter number to push in stack 1\n";
                int num;
                cin >> num;
                push_1(S1, num);
                break;
            }
            case 2: {
                cout << pop_1(S1) << endl;
                break;
            }
            case 3: {
                cout << peek_1(S1) << endl;
                break;
            }
            case 4: {
                cout << "Enter number to push in stack 2\n";
                int num;
                cin >> num;
                push_2(S1, num);
                break;
            }
            case 5: {
                cout << pop_2(S1) << endl;
                break;
            }
            case 6: {
                cout << peek_2(S1) << endl;
                break;
            }
        }
    }
    return 0;
}
