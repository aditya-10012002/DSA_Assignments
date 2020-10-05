#include<iostream>
using namespace std;

struct queue {
    int div;
    int size[500];
    int front[500];
    int rear[500];
    int elements[1000];
};
void enqueue(queue &Q, int tag, int x) {
    if((Q.rear[tag]+1)%Q.div == Q.front[tag])
    cout << "queue is full\n";
    else {
        if(Q.front[tag] == -1) {
            Q.front[tag] = 0;
            Q.rear[tag] = 0;
        } else {
            Q.rear[tag] = (Q.rear[tag]+1)%Q.div;
        }
        Q.elements[Q.size[tag] + Q.rear[tag]] = x;
    }
}
int dequeue(queue &Q, int tag) {
    int t = -1;
    if(Q.front[tag] == -1)
    cout << "queue is empty\n";
    else {
        if(Q.front[tag] == Q.rear[tag]) {
            t = Q.elements[Q.size[tag] + Q.front[tag]];
            Q.front[tag] = -1;
            Q.rear[tag] = -1;
        }
        else {
            t = Q.elements[Q.size[tag] + Q.front[tag]];
            Q.front[tag] = (Q.front[tag]+1)%Q.div;
        }
    }
    return t;
}
int main() {
    queue Q1;
    int k;
    cout << "Enter the value of k for k queues\n";
    cin >> k;
    Q1.div = 1000/k;
    Q1.size[0] = 0;
    for(int i=0;i<k;i++) {
        Q1.size[i+1] = Q1.div*(i+1);
        Q1.front[i] = -1;
        Q1.rear[i] = -1;
    }
    while (true) {
        cout << "Enter 1 to enqueue, 2 to dequeue\n";
        cout << "Enter 0 to break out\n";
        int ch;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                int m;
                cout << "Enter in which queue you want to enqueue in 1-index\n";
                cin >> m;
                cout << "Enter number to enqueue\n";
                int num;
                cin >> num;
                enqueue(Q1, m-1, num);
                break;
            }
            case 2: {
                int m;
                cout << "Enter in which queue you want to dequeue in 1-index\n";
                cin >> m;
                cout << dequeue(Q1, m-1) << endl;
                break;
            }
        }
    }

    return 0;
}
