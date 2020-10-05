#include<iostream>
using namespace std;

struct cnode {
    int data;
    node *next;
};
typedef cnode *cptr;

void insert(cptr C) {
    int k;
    cin >> k;
    if(k != -1) {
        cptr T = new(cnode);
        T->data = k;
        T->next = nullptr;
        C->next = T;
        insert(C->next);
    }
}
bool isDone(cptr S, cptr E, int data) {
    if(S == E)
    return false;
    else if(S->data == data)
    return true;
    else
    return isDone(S->next, E, data);
}
void print_all(cptr S, cptr C) {
    if(!isDone(S, C, C->data)) {
        
    } else {
        print_all(S, C->next);
    }
}

int main() {
    int k;
    cptr E, C1 = new(cnode);
    cin >> k;
    C1->data = k;
    C1->next = nullptr;
    insert(C1);
    E = C1;
    while(E->next != nullptr)
    E = E->next;
    E->next = C1;
    print_all(C1);
    return 0;
}
