#include<iostream>
using namespace std;

union U {
    int element_int;
    char element_char;
    float element_float;
};
struct stack2 {
    int size;
    int top;
    U elements[50];
    int tag[50];
};
void push_2(struct stack2 &S) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else {
        cout << "Enter 1 to enter integer, 2 for char, 3 for float\n";
        cin >> S.tag[++S.top];
        cout << "Enter number to push in stack 1\n";
        if(S.tag[S.top] == 1)
        cin >> S.elements[S.top].element_int;
        else if(S.tag[S.top] == 2)
        cin >> S.elements[S.top].element_char;
        else
        cin >> S.elements[S.top].element_float;
    }
}
U pop_2(struct stack2 &S, int &t) {
    if(S.top == -1) {
        U a;
        a.element_int = -1;
        return a;
    } else {
        t = S.tag[S.top];
        return S.elements[S.top--];
    }
}
U peek_2(struct stack2 &S, int&t) {
    if(S.top == -1) {
        U a;
        a.element_int = -1;
        return a;
    } else {
        t = S.tag[S.top];
        return S.elements[S.top];
    }
}
int main() {
    struct stack2 S1;
    S1.size = 50;
    S1.top = -1;
    while (true) {
        cout << "Enter 1 to push in stack1, 2 to pop in stack 1, 3 to peek in stack 1\n";
        cout << "Enter 0 to break out\n";
        int ch;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                push_2(S1);
                break;
            }
            case 2: {
                int t;
                U var = pop_2(S1, t);
                if(t == 1)
                cout << var.element_int << endl;
                else if(t == 2)
                cout << var.element_char << endl;
                else
                cout << var.element_float << endl;
                break;
            }
            case 3: {
                int t;
                U var = peek_2(S1, t);
                if(t == 1)
                cout << var.element_int << endl;
                else if(t == 2)
                cout << var.element_char << endl;
                else
                cout << var.element_float << endl;
                break;
            }
        }
    }
    return 0;
}
