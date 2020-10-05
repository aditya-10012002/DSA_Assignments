#include<iostream>
using namespace std;

struct cnode {
    int data;
    cnode *next;
};
typedef cnode *cptr;

void insert(cptr C) {
    int k;
    cin >> k;
    cptr T = new(cnode);
    T->data = k;
    T->next = nullptr;
    C->next = T;
    if(k == 0)
    return;
    insert(C->next);
}
int Delete(cptr P) {
    cptr active = P->next;
    P->next = active->next;
    int del = active->data;
    active->next = nullptr;
    free(active);
    return del;
}
void removal(cptr C, int m) {
    int k;
    while(C->next != C) {
        k = m-2;
        while(k-- > 0)
        C = C->next;
        cout << Delete(C) << " ";
        C = C->next;
    }
    cout << endl;
}

int main() {
    int k, n, m;
    cptr E, C1 = new(cnode);
    cin >> n;
    cin >> k;
    C1->data = k;
    C1->next = nullptr;
    insert(C1);
    cin >> m;
    E = C1;
    while(E->next != nullptr)
    E = E->next;
    E->next = C1;
    removal(C1, m);
    return 0;
}
