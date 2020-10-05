#include<iostream>
using namespace std;

struct stack_k {
    int top[50];
    int size[50];
    int elements[200];
};
void push_k(struct stack_k &S, int x, int tag) {
    if(S.top[tag] == S.size[tag]-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top[tag]] = x;
}
int pop_k(struct stack_k &S, int tag) {
    if(S.top[tag] == -1 && tag == 0)
    return -1;
    else if(S.top[tag] == S.size[tag-1]-1)
    return -1;
    else
    return S.elements[S.top[tag]--];
}
int peek_k(struct stack_k &S, int tag) {
    if(S.top[tag] == -1 && tag == 0)
    return -1;
    else if(S.top[tag] == S.size[tag-1]-1)
    return -1;
    else
    return S.elements[S.top[tag]];
}
int main() {
    struct stack_k S1;
    int k;
    cout << "Enter the value of k for k stacks\n";
    cin >> k;
    int div = 200/k;
    for(int i=0;i<k;i++) {
        S1.size[i] = div*(i+1);
        S1.top[i] = S1.size[i]-div-1;
    }
    while (true) {
        cout << "Enter 1 to push in stack, 2 to pop in stack, 3 to peek in stack\n";
        cout << "Enter 0 to break out\n";
        int ch;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                int m;
                cout << "Enter in which stack you want to push in 1-index\n";
                cin >> m;
                cout << "Enter number to push in stack 1\n";
                int num;
                cin >> num;
                push_k(S1, num, m-1);
                break;
            }
            case 2: {
                int m;
                cout << "Enter in which stack you want to pop in 1-index\n";
                cin >> m;
                cout << pop_k(S1, m-1) << endl;
                break;
            }
            case 3: {
                int m;
                cout << "Enter in which stack you want to pop in 1-index\n";
                cin >> m;
                cout << peek_k(S1, m-1) << endl;
                break;
            }
        }
    }
    return 0;
}
