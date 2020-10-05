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
void push(queue &Q1, int x) {
    enqueue(Q1, x);
}
void push_costly(queue &Q1, int x) {
    struct queue Q2;
    Q2.size = 50;
    Q2.front = -1;
    Q2.rear = -1;

    while(Q1.rear != -1)
    enqueue(Q2, dequeue(Q1));
    enqueue(Q1, x);
    while(Q2.rear != -1)
    enqueue(Q1, dequeue(Q2));
}
int pop(queue &Q1) {
    return dequeue(Q1);
}
int pop_costly(queue &Q1) {
    struct queue Q2;
    Q2.size = 50;
    Q2.front = -1;
    Q2.rear = -1;

    while(Q1.front != Q1.rear)
    enqueue(Q2, dequeue(Q1));
    int k = dequeue(Q1);
    while(Q2.rear != -1)
    enqueue(Q1, dequeue(Q2));
    return k;
}
void costly_push() {
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    while(true) {
        cout << "Enter 1 to push, 2 to pop, -1 to get out\n";
        int ch;
        cin >> ch;
        if(ch == -1)
        return;
        switch(ch) {
        case 1:
            cout << "Enter the number to push\n";
            int num;
            cin >> num;
            push_costly(Q1, num);
            break;
        case 2:
            cout << "Popped value is " << pop(Q1) << endl;
            break;
        }
    }
}
void costly_pop() {
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    while(true) {
        cout << "Enter 1 to push, 2 to pop, -1 to get out\n";
        int ch;
        cin >> ch;
        if(ch == -1)
        return;
        switch(ch) {
        case 1:
            cout << "Enter the number to push\n";
            int num;
            cin >> num;
            push(Q1, num);
            break;
        case 2:
            cout << "Popped value is " << pop_costly(Q1) << endl;
            break;
        }
    }
}
int main() {
    cout << "Enter 1 to activate stack with costly push, 2 to activate costly pop one\n";
    int ch;
    cin >> ch;
    switch(ch) {
    case 1:
        costly_push();
        break;
    case 2:
        costly_pop();
        break;
    }
}
