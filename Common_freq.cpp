#include<iostream>
using namespace std;

struct lnode {
    int num;
    lnode *next;
};
struct listnode {
    int data;
    int count;
    lnode *link;
    listnode *lnext;
};
typedef lnode *lptr;
typedef listnode *llptr;

void insert_ll(llptr &L, int x) {
    if(x == 10)
    return;
    if(L == nullptr) {
        L = new(listnode);
        L->data = x;
        L->count = 0;
        L->link = nullptr;
        L->lnext = nullptr;
    } else {
        llptr T = new(listnode);
        T->data = x;
        T->count = 0;
        T->link = nullptr;
        T->lnext = nullptr;
        L->lnext = T;
    }
    insert_ll(L->lnext, x+1);
}
void insert_l(llptr L) {
    int x;
    cin >> x;
    if(x == -1)
    return;
    llptr T1 = L;
    while(T1->data != x)
    T1 = T1->lnext;
    T1->count = T1->count + 1;
    if(T1->link == nullptr) {
        T1->link = new(lnode);
        T1->link->num = x;
        T1->link->next = nullptr;
    } else {
        lptr T2 = T1->link;
        while(T2->next != nullptr)
        T2 = T2->next;
        lptr T = new(lnode);
        T->num = x;
        T->next = nullptr;
        T2->next = T;
    }
    insert_l(L);
}
void top_three(llptr LL) {
    int c=0;
    bool flag = false;
    for(int i=10;(i>=0) && (c<3);i--) {
        llptr T = LL;
        while(T != nullptr) {
            if(T->count == i) {
                flag = true;
                cout << T->data << " " << T->count << endl;
            }
            T = T->lnext;
        }
        if(flag)
        c++;
    }
}
int main() {
    llptr LL = nullptr;
    insert_ll(LL, 0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    insert_l(LL);
    top_three(LL);
    return 0;
}
