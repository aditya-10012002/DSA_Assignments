#include<iostream>
using namespace std;

struct lnode {
    int data;
    lnode *next;
};
struct slnode {
    lnode *next1;
    lnode *next2;
    slnode *snext;
};
typedef lnode *lptr;
typedef slnode *slptr;

void insert(lptr L) {
    int n;
    cin >> n;
    if(n == -1)
    return;
    lptr T = new(lnode);
    T->data = n;
    T->next = nullptr;
    L->next = T;
    insert(L->next);
}
void print(slptr SL) {
    while(SL != nullptr) {
        lptr T = SL->next1;
        if(SL->snext != nullptr) {
            while(T != SL->snext->next1) {
                cout << T->data << " ";
                T = T->next;
            }
            T = SL->next2;
            while(T != SL->snext->next2) {
                cout << T->data << " ";
                T = T->next;
            }
        } else {
            while(T != nullptr) {
                cout << T->data << " ";
                T = T->next;
            }
            T = SL->next2;
            while(T != nullptr) {
                cout << T->data << " ";
                T = T->next;
            }
        }
        SL = SL->snext;
    }
    cout << endl;
}
void make_SL(lptr L1, lptr L2) {
    slptr T, T1, SL = new(slnode);
    SL->next1 = (L1->data <= L2->data)?L1:L2;
    if(SL->next1 == L1) {
        while(L1->data <= L2->data)
        L1 = L1->next;
    } else {
        while(L2->data <= L1->data)
        L2 = L2->next;
    }
    SL->next2 = (L1->data <= L2->data)?L1:L2;
    SL->snext = nullptr;
    T1 = SL;
    while(L1 != nullptr && L2 != nullptr) {
        if(T1->next1 == L1) {
            while(L1 != nullptr && L1->data <= L2->data)
            L1 = L1->next;
        } else {
            while(L2 != nullptr && L2->data <= L1->data)
            L2 = L2->next;
        }
        T = new(slnode);
        T->next1 = L1;
        while(L1 != nullptr && L1->data <= L2->data)
        L1 = L1->next;
        T->next2 = L2;
        T->snext = nullptr;
        T1->snext = T;
        T1 = T1->snext;
    }
    print(SL);
}
int main() {
    int n;
    lptr L1, L2;
    cin >> n;
    L1 = new(lnode);
    L1->data = n;
    L1->next = nullptr;
    insert(L1);
    cin >> n;
    L2 = new(lnode);
    L2->data = n;
    L2->next = nullptr;
    insert(L2);
    make_SL(L1, L2);
    return 0;
}
