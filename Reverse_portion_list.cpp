#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
typedef node *lptr;

void insert(lptr P, int num) {
    lptr T;
    T = new(node);
    T->data = num;
    T->next = nullptr;
    while(P->next != nullptr)
    P = P->next;
    P->next = T;
}

void rev(lptr &P1, lptr T1) {
    if(T1 != nullptr) {
        rev(P1, T1->next);
        P1->data = T1->data;
        P1 = P1->next;
    }
}
void reverse(lptr P, int i, int j) {
    lptr T, P1=P;
    T = new(node);
    j -= i;
    while(i-- > 1) {
        P = P->next;
        P1 = P1->next;
    }
    T->data = P1->data;
    T->next = nullptr;

    while(j-- > 0) {
        P1 = P1->next;
        insert(T, P1->data);
    }
    rev(P, T);
}

void print(lptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}
int main() {
    lptr L1;
    int n;
    L1 = new(node);
    cin >> n;
    L1->data = n;
    L1->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L1, n);
        cin >> n;
    }
    int i, j;
    cin >> i >> j;
    reverse(L1, i, j);
    print(L1);
    return 0;
}
