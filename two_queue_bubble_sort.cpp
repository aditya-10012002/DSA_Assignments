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
int main() {
    struct queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    struct queue Q2;
    Q2.size = 50;
    Q2.front = -1;
    Q2.rear = -1;

    int n;
    cout << "Enter the size\n";
    cin >> n;
    cout << "Enter the array elements\n";
    int c;
    for(int i=0;i<n;i++) {
        cin >> c;
        enqueue(Q1, c);
    }
    while(n-- > 0) {
        c = dequeue(Q1);
        for(int i=0;i<n;i++) {
            int a = dequeue(Q1);
            if(a >= c)
            enqueue(Q1, a);
            else {
                enqueue(Q1, c);
                c = a;
            }
        }
        enqueue(Q2, c);
    }

    while(Q2.rear != -1)
    cout << dequeue(Q2) << " ";
    cout << endl;

    return 0;
}
