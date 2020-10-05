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
void removal_v2(cptr C) {
    while(C->next != C) {
        Delete(C);
        if(C->next == C)
        break;
        Delete(C);
        C = C->next;
    }
    cout << C->data << endl;
}

int main() {
    int k = 1, n;
    cptr E, C1 = new(cnode);
    cin >> n;
    C1->data = k;
    C1->next = nullptr;
    insert(C1, k+1, n);
    E = C1;
    while(E->next != nullptr)
    E = E->next;
    E->next = C1;
    removal_v2(C1);
    return 0;
}
