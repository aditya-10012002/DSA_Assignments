//Be an  'Alias' of 'Genius'
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

void print(lptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

void Add_front(lptr &P, int k) {
    lptr T;
    T = new(node);
    T->data = k;
    T->next = P;
    P = T;
}

void Add_before(lptr &P, int x, int y) {
    lptr T;
    T = new(node);
    T->data = x;
    if(y == P->data) {
        Add_front(P, x);
    } else {
        lptr T1 = P;
        while(P->next->data != y)
        P = P->next;
        T->next = P->next;
        P->next = T;
        P = T1;
    }
}
void Add_after(lptr P, int x, int y) {
    lptr T;
    T = new(node);
    T->data = x;
    while(P->data != y)
    P = P->next;
    T->next = P->next;
    P->next = T;
}
void Delete_front(lptr &P) {
    P = P->next;
}
void Delete(lptr &P, int k) {
    if(k == P->data) {
        Delete_front(P);
    } else {
        lptr active, T1 = P;
        while(P->next->data != k)
        P = P->next;
        active = P->next;
        P->next = P->next->next;
        active->next = nullptr;
        free(active);
        P = T1;
    }
}
void Delete_min(lptr &P) {
    int min = P->data;
    lptr T = P;
    while(P != nullptr) {
        min = (min < P->data)?min:P->data;
        P = P->next;
    }
    P = T;
    Delete(P, min);
}
void Delete_max(lptr &P) {
    int max = P->data;
    lptr T = P;
    while(P != nullptr) {
        max = (max > P->data)?max:P->data;
        P = P->next;
    }
    P = T;
    Delete(P, max);
}
int main() {
    lptr L;
    int n, x, y;
    L = new(node);
    cin >> n;
    L->data = n;
    L->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L, n);
        cin >> n;
    }
    print(L);
    cin >> n;
    Add_front(L, n);
    print(L);
    cin >> x >> y;
    Add_before(L, x, y);
    print(L);
    cin >> x >> y;
    Add_after(L, x, y);
    print(L);
    cin >> n;
    Delete(L, n);
    print(L);
    Delete_min(L);
    print(L);
    Delete_max(L);
    print(L);
    return 0;
}
