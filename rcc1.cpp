#include<iostream>
using namespace std;

struct stack {
    int size;
    int top;
    char elements[50];
};
void push(struct stack &S, char x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
char pop(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top--];
}
char peek(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top];
}
struct queue {
    int size;
    int front;
    int rear;
    char elements[50];
};
void enqueue(queue &Q, char x) {
    if((Q.rear+1)%Q.size == Q.front)
    cout << "queue is full\n";
    else {
        if(Q.front == -1) {
            Q.front = 0;
            Q.rear = 0;
        } else {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear] = x;
    }
}
char dequeue(queue &Q) {
    int t = -1;
    if(Q.front == -1)
    cout << "queue is empty\n";
    else {
        if(Q.front == Q.rear) {
            t = Q.elements[Q.front];
            Q.front = -1;
            Q.rear = -1;
        }
        else {
            t = Q.elements[Q.front];
            Q.front = (Q.front+1)%Q.size;
        }
    }
    return t;
}
void Reverse() {
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    stack S1;
    S1.top = -1;
    S1.size = 50;
    char arr[50];
    int i=0;
    for(i=0;;i++) {
        char ch;
        cin >> ch;
        if(ch =='#')
        break;
        enqueue(Q1, ch);
    }
    while(Q1.rear != -1) {
        push(S1, dequeue(Q1));
    }
    bool flag = true;
    for(int j=0;j<i;j++) {
        if(arr[j] != pop(S1)) {
            flag = false;
            break;
        }
    }
    if(flag)
    cout << "1\n";
    else
    cout << "0\n";
}
void check() {
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    stack S1;
    S1.top = -1;
    S1.size = 50;
    int i=0;
    for(i=0;;i++) {
        char t;
        cin >> t;
        if(t == '#')
        break;
        enqueue(Q1, t);
    }
    while(Q1.rear != -1) {
        push(S1, dequeue(Q1));
    }
    while(S1.top != -1)
    cout << pop(S1) << " ";
    cout << endl;
}
int main() {
    Reverse();
    check();
    return 0;
}
