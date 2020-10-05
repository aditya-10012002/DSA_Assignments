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

void singleScan(lptr SP, lptr FP) {
    while(FP->next != NULL) {
        if(FP->next->next == NULL)
        break;
        FP = FP->next->next;
        SP = SP->next;
    }
    if(FP->next != NULL)
    cout << "There are two middle elements " << SP->data << " " << SP->next->data << endl;
    else
    cout << "There is a middle elements " << SP->data << endl;
}

int main() {
    lptr L;
    L = new(Lnode);
    int x;
    cout << "Enter numbers to add and give -1 to terminate the input buffer\n";
    cin >> x;
    L->data = x;
    L->next = NULL;
    while(true) {
        cin >> x;
        if(x < 0)
        break;
        insert(L, x);
    }
    singleScan(L, L);
}
