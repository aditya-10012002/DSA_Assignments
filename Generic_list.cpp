#include<iostream>
using namespace std;

union U {
    int num;
    char ch;
};

struct node {
    U data;
    node *next;
};

struct node_tag {
    int data;
    node_tag *next;
};

typedef node *lptr;
typedef node_tag *ltag;

void insert(lptr P, ltag Tg,  U num, int tg) {
    lptr T;
    ltag T1;
    T = new(node);
    T->data = num;
    T->next = nullptr;
    T1 = new(node_tag);
    T1->data = tg;
    T1->next = nullptr;
    if(tg == 1) {
        while(P->next != nullptr) {
            P = P->next;
            Tg = Tg->next;
        }
        P->next = T;
        Tg->next = T1;
    } else {
        while(Tg->next != nullptr && Tg->next->data != 1) {
            Tg = Tg->next;
            P = P->next;
        }
        T->next = P->next;
        P->next = T;
        T1->next = Tg->next;
        Tg->next = T1;
    }
}
void print(lptr P, ltag Tg) {
    while(Tg != nullptr) {
        if(Tg->data == 0)
        cout << P->data.ch << " ";
        else
        cout << P->data.num << " ";
        P = P->next;
        Tg = Tg->next;
    }
    cout << endl;
}
int main() {
    lptr L1;
    ltag Tg;
    int t;
    U n;
    L1 = new(node);
    Tg = new(node_tag);
    cin >> t;
    Tg->data = t;
    Tg->next = nullptr;
    if(t == 0)
    cin >> n.ch;
    else
    cin >> n.num;
    L1->data = n;
    L1->next = nullptr;
    cin >> t;
    if(t == 0)
    cin >> n.ch;
    else
    cin >> n.num;
    while(true) {
        insert(L1, Tg, n, t);
        cin >> t;
        if(t == 0)
        cin >> n.ch;
        else
        cin >> n.num;
        if(t == 0) {
            if(n.ch == '#')
            break;
        }
    }
    print(L1, Tg);
    return 0;
}
