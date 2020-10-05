#include<iostream>
using namespace std;

struct lnode {
    char ch;
    int num;
    lnode *next;
};
struct listnode {
    lnode *data;
    listnode *lnext;
};
typedef lnode *lptr;
typedef listnode *llptr;

void insert(lptr L) {
    int x;
    char ch;
    cin >> ch;
    cin >> x;
    if(ch == '#' && x == -1)
    return;
    lptr T = new(lnode);
    T->ch = ch;
    T->num = x;
    T->next = nullptr;
    L->next = T;
    insert(L->next);
}
void insert(lptr L, int x, char ch) {
    lptr T = new(lnode);
    T->ch = ch;
    T->num = x;
    T->next = nullptr;
    L->next = T;
}
lptr intersection(lptr T, lptr T1) {
    lptr C = nullptr;
    while(T != nullptr) {
        lptr T2 = T1;
        while(T2 != nullptr) {
            if(T2->ch == T->ch && T2->num == T->num) {
                if(C == nullptr) {
                    C = new(lnode);
                    C->ch = T->ch;
                    C->num = T->num;
                } else
                insert(C, T->num, T->ch);
            }
            T2 = T2->next;
        }
        T = T->next;
    }
    return C;
}
void print_l(lptr L) {
    if(L != nullptr) {
        cout << L->ch << L->num << " ";
        print_l(L->next);
    }
}
void print_common(llptr LL) {
    lptr T1, T = LL->data;
    LL = LL->lnext;
    while(LL != nullptr) {
        T1 = LL->data;
        T = intersection(T, T1);
        LL = LL->lnext;
    }
    print_l(T);
    cout << endl;
}
void print_ll(llptr LL) {
    while(LL != nullptr) {
        lptr L = LL->data;
        while(L != nullptr) {
            cout << L->ch << L->num << " ";
            L = L->next;
        }
        LL = LL->lnext;
    }
    cout << endl;
}
int main() {
    char ch;
    int n=3, x;
    llptr T, T1, LL = new(listnode);
    LL->data = new(lnode);
    LL->lnext = nullptr;
    cin >> ch;
    cin >> x;
    LL->data->ch = ch;
    LL->data->num = x;
    insert(LL->data);
    T1 = LL;
    for(int i=0;i<n-1;i++) {
        T = new(listnode);
        T->data = new(lnode);
        T->lnext = nullptr;
        cin >> ch;
        cin >> x;
        T->data->ch = ch;
        T->data->num = x;
        insert(T->data);
        T1->lnext = T;
        T1 = T1->lnext;
    }
    print_ll(LL);
    print_common(LL);
    return 0;
}
