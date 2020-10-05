#include<iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int rear;
    int elements[50];
};
void enqueue(queue &Q, int x) {
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
int dequeue(queue &Q) {
    int t;
    if(Q.front == -1)
    t = -1;
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
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    stack S1;
    S1.top = -1;
    S1.size = 50;
    int n;
    cout << "Enter the length\n";
    cin >> n;
    int m = n/2;
    int temp;
    for(int i=0;i<m;i++) {
        cin >> temp;
        enqueue(Q1, temp);
    }
    for(int i=m;i<n;i++) {
        cin >> temp;
        push(S1, temp);
    }
    reverse_stack(S1);
    for(int i=0;i<m;i++) {
        cout << dequeue(Q1) << " " << pop(S1) << " ";
    }
    cout << endl;
}
