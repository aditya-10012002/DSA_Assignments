#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
typedef node *lptr;

void push(lptr P, int num) {
    lptr T;
    T = new(node);
    T->data = num;
    T->next = nullptr;
    while(P->next != nullptr)
    P = P->next;
    P->next = T;
}
int Delete_front(lptr &P) {
    int num = P->data;
    lptr act = P;
    P = P->next;
    free(act);
    return num;
}
int dequeue(lptr &P) {
    if(P == nullptr) {
        cout << "Queue is empty\n";
        return -1;
    } else {
        return Delete_front(P);
    }
}
int pop(lptr &P) {
    if(P == nullptr) {
        cout << "Stack is empty\n";
        return -1;
    } else if(P->next == nullptr) {
        return Delete_front(P);
    } else {
        lptr active, T1 = P;
        while(P->next->next != nullptr)
        P = P->next;
        active = P->next;
        int num = active->data;
        P->next = nullptr;
        free(active);
        P = T1;
        return num;
    }
}
int main() {
    lptr L;
    L = nullptr;
    cout << "Enter 1 for stack, 2 for queue\n";
    int ch1;
    cin >> ch1;
    if(ch1 == 1) {
        while (true) {
        cout << "Enter 1 to push in stack, 2 to pop in stack\n";
        cout << "Enter 0 to break out\n";
        int ch, x;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                cout << "Enter number to push\n";
                cin >> x;
                if(L == nullptr) {
                    L = new(node);
                    L->data = x;
                    L->next = nullptr;
                } else {
                    push(L, x);
                }
                break;
            }
            case 2: {
                int t = pop(L);
                if(t != -1)
                cout << "Popped element is " << t << endl;
                break;
            }
        }
    }
    } else {
        while (true) {
        cout << "Enter 1 to enqueue, 2 to dequeue\n";
        cout << "Enter 0 to break out\n";
        int ch, x;
        cin >> ch;
        if(ch == 0)
        return 0;
        switch(ch) {
            case 1: {
                cout << "Enter number to enqueue\n";
                cin >> x;
                if(L == nullptr) {
                    L = new(node);
                    L->data = x;
                    L->next = nullptr;
                } else {
                    push(L, x);
                }
                break;
            }
            case 2: {
                int t = dequeue(L);
                if(t != -1)
                cout << "dequeued element is " << t << endl;
                break;
            }
        }
    }
    }
    return 0;
}
