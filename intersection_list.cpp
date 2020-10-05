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

void find(lptr L1, lptr L2) {
    lptr T1 = L1, T2;
    while(T1->next != nullptr) {
        T2 = L2;
        while(T2 != nullptr) {
            if(T2 == T1) {
                cout << T1->data << endl;
                return;
            }
            T2 = T2->next;
        }
        T1 = T1->next;
    }
}
void print(lptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}
int main() {
    lptr L1, L2;
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
    L2 = new(node);
    cin >> n;
    L2->data = n;
    L2->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L2, n);
        cin >> n;
    }
    lptr T1=L1, T2=L2;
    while(T2->next != nullptr)
    T2 = T2->next;
    while(T1->data != 6)
    T1 = T1->next;
    T2->next = T1;
    find(L1, L2);
    return 0;
}
