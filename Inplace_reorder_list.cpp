#include<iostream>
using namespace std;

struct Lnode {
    int data;
    Lnode *next;
};
typedef Lnode *lptr;

void insert(lptr P, int k) {
    lptr T;
    T = new(Lnode);
    T->data = k;
    T->next = NULL;
    while(P->next != NULL)
    P = P->next;
    P->next = T;
}
void insertAfter(lptr P, int x, int y) {
    // Insert x just after y in the linked list P.
    lptr T;
    T = new(Lnode);
    T->data = x;
    while(P->data != y)
    P = P->next;
    T->next = P->next;
    P->next = T;
}
int count_nodes(lptr P) {
    int c=0;
    while(P != NULL) {
        c++;
        P = P->next;
    }
    return c;
}
void Delete_front(lptr &P) {
    P = P->next;
}
void Delete(lptr &P, int k) {
    if(k == P->data) {
        Delete_front(P);
    } else {
        lptr active, T1 = P;
        while(P->next->data != k)
        P = P->next;
        active = P->next;
        P->next = P->next->next;
        active->next = nullptr;
        free(active);
        P = T1;
    }
}
void reorder(lptr P) {
    lptr T1=P, T2;
    int c = count_nodes(P);
    while(T1->next != NULL) {
        T2 = T1;
        while(T2->next != NULL) {
            T2 = T2->next;
        }
        int num = T2->data;
        Delete(P, num);
        insertAfter(P, num, T1->data);
        T1 = T1->next->next;
        if(T1 == NULL)
        break;
    }
}
void print(lptr P) {
    while(P != NULL) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}
int main() {
    lptr L;
    L = new(Lnode);
    int x;
    //cout << "Enter numbers to add and give -1 to terminate the input buffer\n";
    cin >> x;
    L->data = x;
    L->next = NULL;
    while(true) {
        cin >> x;
        if(x < 0)
        break;
        insert(L, x);
    }
    reorder(L);
    print(L);
    return 0;
}
