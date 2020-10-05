#include<iostream>
using namespace std;

struct cnode {
    int data;
    cnode *next;
};
typedef cnode *cptr;

void insert(cptr C, int k, int n) {
    cptr T = new(cnode);
    T->data = k;
    T->next = nullptr;
    C->next = T;
    if(k == n)
    return;
    insert(C->next, k+1, n);
}
void Delete(cptr P) {
    cptr active = P->next;
    P->next = active->next;
    active->next = nullptr;
    free(active);
}
void print(cptr C) {
    while(C->next->data > C->data)
    C = C->next;
    C = C->next;
    for(int i=1;i<=30;i++) {
        if(C->data == i) {
            cout << "A";
            C = C->next;
        } else {
            cout << "B";
        }
    }
    cout << endl;
}
void removal_v3(cptr C, int m) {
    int k, c=15;
    while(c-- > 0) {
        k = m-2;
        while(k-- > 0)
        C = C->next;
        Delete(C);
        C = C->next;
    }
    print(C);
}

int main() {
    int k=1, n=30;
    cptr E, C1 = new(cnode);
    C1->data = k;
    C1->next = nullptr;
    insert(C1, k+1, n);
    E = C1;
    while(E->next != nullptr)
    E = E->next;
    E->next = C1;
    removal_v3(C1, 9);
    return 0;
}
