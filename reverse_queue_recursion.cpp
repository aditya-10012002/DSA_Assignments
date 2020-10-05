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
void reversed_queue(queue &Q1) {
    if(Q1.rear != -1) {
        int num = dequeue(Q1);
        reversed_queue(Q1);
        enqueue(Q1, num);
    }
}
int main() {
    queue Q1;
    Q1.front = -1;
    Q1.rear = -1;
    Q1.size = 50;
    int n;
    cout << "Enter length\n";
    cin >> n;
    int temp;
    for(int i=0;i<n;i++) {
        cin >> temp;
        enqueue(Q1, temp);
    }
    reversed_queue(Q1);
    while(Q1.rear != -1)
    cout << dequeue(Q1) << " ";
    cout << endl;
}
