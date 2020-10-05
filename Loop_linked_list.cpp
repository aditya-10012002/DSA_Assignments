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
void loop(lptr P) {
    lptr SP=P->next, FP=P->next->next;
    int c=0, num;
    while(FP->next != NULL) {
        SP = SP->next;
        FP = FP->next->next;
        if(SP == FP) {
            /*while(SP->next != FP)
            SP = SP->next;
            num = SP->data;*/
            c=1;
            break;
        }
    }
    SP=P;
    FP=P;
    num = -1;
    if(c == 1) {
        while(true) {
        SP = SP->next;
        int d=0;
        FP = SP->next;
        while(d<100) {
            d++;
            FP = FP->next;
            if(FP == SP) {
                num = SP->data;
                break;
            }
        }
        if(num != -1)
        break;
        }
    }
    if(c == 0)
    cout << '0' << endl;
    else {
        cout << c << endl;
        cout << num << endl;
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
    lptr T1=L, T2=L;
    while(T1->data != 2)
    T1 = T1->next;
    while(T2->next != NULL)
    T2 = T2->next;

    T2->next = T1;
    loop(L);
    return 0;
}
