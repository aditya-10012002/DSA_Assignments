#include<iostream>
using namespace std;

union U {
    int num;
    char ch;
};
struct union_queue {
    int size;
    int front;
    int rear;
    int tag[50];
    U elements[50];
};
void enqueue(union_queue &Q, U x, int tg) {
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
        Q.tag[Q.rear] = tg;
    }
}
U dequeue(union_queue &Q, int &tg) {
    U t;
    if(Q.front == -1) {
        cout << "queue is empty\n";
        t.num = -1;
    } else {
        if(Q.front == Q.rear) {
            t = Q.elements[Q.front];
            tg = Q.tag[Q.front];
            Q.front = -1;
            Q.rear = -1;
        }
        else {
            t = Q.elements[Q.front];
            tg = Q.tag[Q.front];
            Q.front = (Q.front+1)%Q.size;
        }
    }
    return t;
}
bool isOperator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/')?true:false;
}
int eval(int n1, int n2, char ch) {
    switch(ch) {
    case '+':
        cout << n1 << " " << n2 << " " << ch << " " << (n1+n2) << endl;
        return n1+n2;
    case '-':
        cout << n1 << " " << n2 << " " << ch << " " << (n1-n2) << endl;
        return n1-n2;
    case '*':
        cout << n1 << " " << n2 << " " << ch << " " << (n1*n2) << endl;
        return n1*n2;
    case '/':
        cout << n1 << " " << n2 << " " << ch << " " << (n1/n2) << endl;
        return (float)n1/n2;
    default:
        return -1;
    }
}
U make_union_int(int num) {
    U a;
    a.num = num;
    return a;
}
U make_union_char(char ch) {
    U a;
    a.ch = ch;
    return a;
}
int main() {
    struct union_queue Q1;
    Q1.size = 50;
    Q1.front = -1;
    Q1.rear = -1;
    string s = "-+*9+28*+4863";
    int n = 13;
    for(int i=0;i<n;i++) {
        if(isOperator(s[i]))
        enqueue(Q1, make_union_char(s[i]), 0);
        else
        enqueue(Q1, make_union_int(s[i]-'0'), 1);
    }
    U a, b, c;
    int tg1, tg2, tg3;
    a = dequeue(Q1, tg1);
    b = dequeue(Q1, tg2);
    while(Q1.front != Q1.rear) {
        c = dequeue(Q1, tg3);
        if(tg1 == 0 && tg2 == 1 && tg3 == 1) {
            enqueue(Q1, make_union_int(eval(b.num, c.num, a.ch)), 1);
            a = dequeue(Q1, tg1);
            b = dequeue(Q1, tg2);
        } else {
            enqueue(Q1, a, tg1);
            a = b;
            tg1 = tg2;
            b = c;
            tg2 = tg3;
        }
    }
    cout << dequeue(Q1, tg1).num << endl;
    return 0;
}
