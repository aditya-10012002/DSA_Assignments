#include<iostream>
using namespace std;

union U {
    int element_int;
    char element_char;
    float element_float;
};
struct union_queue {
    int size;
    int front;
    int rear;
    U elements[50];
    int tag[50];
};
void enqueue(union_queue &Q) {
    if((Q.rear+1)%Q.size == Q.front)
    cout << "queue is full\n";
    else {
        if(Q.front == -1) {
            Q.front = 0;
            Q.rear = 0;
        } else {
            Q.rear = (Q.rear+1)%Q.size;
        }
        cout << "Enter 1 to enter integer, 2 for char, 3 for float\n";
        cin >> Q.tag[Q.rear];
        cout << "Enter number to push in stack 1\n";
        if(Q.tag[Q.rear] == 1)
        cin >> Q.elements[Q.rear].element_int;
        else if(Q.tag[Q.rear] == 2)
        cin >> Q.elements[Q.rear].element_char;
        else
        cin >> Q.elements[Q.rear].element_float;
    }
}
U dequeue(union_queue &Q, int &t) {
    U a;
    if(Q.front == -1) {
        cout << "queue is empty\n";
        a.element_int = -1;
        return a;
    } else {
        if(Q.front == Q.rear) {
            t = Q.tag[Q.front];
            a = Q.elements[Q.front];
            Q.front = -1;
            Q.rear = -1;
        }
        else {
            t = Q.tag[Q.front];
            a = Q.elements[Q.front];
            Q.front = (Q.front+1)%Q.size;
        }
        return a;
    }
}
int main() {
    union_queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    while (true) {
        cout << "Enter 1 to enqueue, 2 to dequeue\n";
        cout << "Enter 0 to break out\n";
        int ch;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                enqueue(Q1);
                break;
            }
            case 2: {
                int t;
                U var = dequeue(Q1, t);
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
