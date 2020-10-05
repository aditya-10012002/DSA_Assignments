#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
typedef node *lptr;

void insert(lptr P, int k) {
    lptr T;
    T = new(node);
    T->data = k;
    T->next = nullptr;
    while(P->next != nullptr)
    P = P->next;
    P->next = T;
}
void Add_front(lptr &P, int k) {
    lptr T;
    T = new(node);
    T->data = k;
    T->next = P;
    P = T;
}
void Add_before(lptr &P, int x, int y) {
    lptr T;
    T = new(node);
    T->data = x;
    if(y == P->data) {
        Add_front(P, x);
    } else {
        lptr T1 = P;
        while(P->next->data != y)
        P = P->next;
        T->next = P->next;
        P->next = T;
        P = T1;
    }
}
void Delete(lptr P, int k) {
    while(P->next->data != k)
    P = P->next;
    lptr active = P->next;
    P->next = P->next->next;
    active->next = nullptr;
    free(active);
}
void insertion_sort(lptr &P) {
    lptr T1=P->next, T2;
    while(T1 != nullptr) {
        T2 = P;
        while( T2 != nullptr && T2->data <= T1->data)
        T2 = T2->next;
        if(T2 != nullptr) {
            int num = T1->data;
            T1 = T1->next;
            Delete(P, num);
            Add_before(P, num, T2->data);
            continue;
        }
        T1 = T1->next;
    }
}
void print(lptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}
int main() {
    lptr L = new(node);
    int x;
    cin >> x;
    L->data = x;
    L->next = nullptr;
    cin >> x;
    while(x != -1) {
        insert(L, x);
        cin >> x;
    }
    insertion_sort(L);
    print(L);
    return 0;
}
