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
void enqueue(stack &S1, int x) {
    push(S1, x);
}
void enqueue_costly(stack &S1, int x) {
    struct stack S2;
    S2.top = -1;
    S2.size = 50;
    while(S1.top != -1)
    push(S2, pop(S1));
    push(S1, x);
    while(S2.top != -1)
    push(S1, pop(S2));
}
int dequeue(stack &S1) {
    return pop(S1);
}
int dequeue_costly(stack &S1) {
    struct stack S2;
    S2.top = -1;
    S2.size = 50;
    while(S1.top > 0)
    push(S2, pop(S1));
    int k = pop(S1);
    while(S2.top != -1)
    push(S1, pop(S2));
    if(k == -1)
    cout << "Queue is empty\n";
    return k;
}
void costly_enqueue() {
    struct stack S1;
    S1.top = -1;
    S1.size = 50;
    while(true) {
        cout << "Enter 1 to enqueue, 2 to dequeue, -1 to get out\n";
        int ch;
        cin >> ch;
        if(ch == -1)
        return;
        switch(ch) {
        case 1:
            cout << "Enter the number to enqueue\n";
            int num;
            cin >> num;
            enqueue_costly(S1, num);
            break;
        case 2:
            cout << "dequeued value is " << dequeue(S1) << endl;
            break;
        }
    }
}
void costly_dequeue() {
    struct stack S1;
    S1.top = -1;
    S1.size = 50;
    while(true) {
        cout << "Enter 1 to enqueue, 2 to dequeue, -1 to get out\n";
        int ch;
        cin >> ch;
        if(ch == -1)
        return;
        switch(ch) {
        case 1:
            cout << "Enter the number to enqueue\n";
            int num;
            cin >> num;
            enqueue(S1, num);
            break;
        case 2:
            cout << "dequeued value is " << dequeue_costly(S1) << endl;
            break;
        }
    }
}
int main() {
    cout << "Enter 1 to activate queue with costly enqueue, 2 to activate costly dequeue one\n";
    int ch;
    cin >> ch;
    switch(ch) {
    case 1:
        costly_enqueue();
        break;
    case 2:
        costly_dequeue();
        break;
    }
    return 0;
}
