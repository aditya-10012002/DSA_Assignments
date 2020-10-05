#include<iostream>
using namespace std;

union U {
    int num;
    char ch;
};

struct Dequeue {
    int f;
    int r;
    int size;
    int tag[50];
    U elements[50];
};
void push_front(Dequeue &DQ, U num, int tg) {
    if((DQ.r+1)%DQ.size == DQ.f) {
        cout << "Dequeue is full\n";
    }
    else {
        if(DQ.f == -1) {
            DQ.f = 0;
            DQ.r = 0;
        } else {
            DQ.f = (DQ.size+DQ.f-1)%DQ.size;
        }
        DQ.elements[DQ.f] = num;
        DQ.tag[DQ.f] = tg;
    }
}

void push_rear(Dequeue &DQ, U num, int tg) {
    if((DQ.r+1)%DQ.size == DQ.f) {
        cout << "Dequeue is full\n";
    }
    else {
        if(DQ.f == -1) {
            DQ.f = 0;
            DQ.r = 0;
        } else {
            DQ.r = (DQ.r+1)%DQ.size;
        }
        DQ.elements[DQ.r] = num;
        DQ.tag[DQ.r] = tg;
    }
}

U pop_front(Dequeue &DQ, int &tg) {
    U k;
    if(DQ.f == -1) {
        cout << "Dequeue is empty\n";
        k.num = -1;
    } else {
        if(DQ.f == DQ.r) {
            k = DQ.elements[DQ.f];
            tg = DQ.tag[DQ.f];
            DQ.f = -1;
            DQ.r = -1;
        } else {
            k = DQ.elements[DQ.f];
            tg = DQ.tag[DQ.f];
            DQ.f = (DQ.f+1)%DQ.size;
        }
    }
    return k;
}

U pop_rear(Dequeue &DQ, int &tg) {
    U k;
    if(DQ.f == -1) {
        cout << "Dequeue is empty\n";
        k.num = -1;
    } else {
        if(DQ.f == DQ.r) {
            k = DQ.elements[DQ.f];
            tg = DQ.tag[DQ.f];
            DQ.f = -1;
            DQ.r = -1;
        } else {
            k = DQ.elements[DQ.r];
            tg = DQ.tag[DQ.r];
            DQ.r = (DQ.size+DQ.r-1)%DQ.size;
        }
    }
    return k;
}
struct queue {
    int size;
    int front;
    int rear;
    int tag[50];
    U elements[50];
};
void enqueue(queue &Q, U x, int tg) {
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
U dequeue(queue &Q, int &tg) {
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
    Dequeue DQ1;
    DQ1.f = -1;
    DQ1.r = -1;
    DQ1.size = 50;
    queue Q1;
    Q1.front = -1;
    Q1.rear = -1;
    Q1.size = 50;

    push_rear(DQ1, make_union_char('N'), 0);
    push_rear(DQ1, make_union_int(17), 1);
    push_rear(DQ1, make_union_char('I'), 0);
    push_rear(DQ1, make_union_char('T'), 0);
    push_rear(DQ1, make_union_int(9), 1);
    push_rear(DQ1, make_union_char('C'), 0);
    push_rear(DQ1, make_union_int(20), 1);
    push_rear(DQ1, make_union_char('S'), 0);
    push_rear(DQ1, make_union_int(21), 1);
    push_rear(DQ1, make_union_char('E'), 0);

    int n = 10;
    while(n-- > 0) {
        U a;int tg;
        a = pop_front(DQ1, tg);
        if(tg == 0)
        push_rear(DQ1, a, 0);
        else
        enqueue(Q1, a, tg);
    }
    int tg;
    while(DQ1.r != -1)
    enqueue(Q1, pop_front(DQ1, tg), 0);

    while(Q1.rear != -1) {
        U a = dequeue(Q1, tg);
        if(tg == 0)
        cout << a.ch << " ";
        else
        cout << a.num << " ";
    }
    cout << endl;
    return 0;
}
