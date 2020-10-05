#include<iostream>
using namespace std;

struct queue2 {
    int size;
    int front;
    int rear;
    string elements[50];
};
void enqueue2(queue2 &Q, string x) {
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
string dequeue2(queue2 &Q) {
    string t="";
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
    int n;
    cout << "Enter the number binary numbers you want\n";
    cin >> n;
    queue2 Q1;
    Q1.front = -1;
    Q1.rear = -1;
    Q1.size = n;
    string s="1";
    enqueue2(Q1, s);
    for(int i=1;i<n;i++) {
        string k = dequeue2(Q1);
        cout << i << " " << k << endl;
        enqueue2(Q1, k+"0");
        enqueue2(Q1, k+"1");
    }
    return 0;
}
