#include<iostream>
using namespace std;

struct dlnode {
    dlnode *left;
    int data;
    dlnode *right;
};
typedef dlnode *dlptr;

void insert(dlptr P, int num) {
    dlptr T = new(dlnode);
    T->data = num;
    T->right = nullptr;
    while(P->right != nullptr)
    P = P->right;
    P->right = T;
    T->left = P;
}

void print(dlptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->right;
    }
    cout << endl;
}

void Add_front(dlptr &P, int k) {
    dlptr T = new(dlnode);
    T->data = k;
    T->right = P;
    T->left = nullptr;
    P = T;
}

void Add_End(dlptr P, int k) {
    dlptr T = new(dlnode);
    T->data = k;
    T->right = nullptr;
    while(P->right != nullptr)
    P = P->right;
    T->left = P;
    P->right = T;
}

void Add_before(dlptr &P, int x, int y) {
    if(y == P->data) {
        Add_front(P, x);
    } else {
        dlptr P1=P, T = new(dlnode);
        T->data = x;
        while(P1->data != y)
        P1 = P1->right;
        T->left = P1->left;
        T->right = P1;
        P1->left->right = T;
        P1->left = T;
    }
}
void Add_after(dlptr P, int x, int y) {
    dlptr T = new(dlnode);
    T->data = x;
    while(P->data != y)
    P = P->right;
    T->left = P;
    T->right = P->right;
    P->right->left = T;
    P->right = T;
}
void Delete_front(dlptr &P) {
    dlptr T = P;
    P = P->right;
    T->right = nullptr;
    P->left = nullptr;
    free(T);
}

void Delete_End(dlptr P) {
    while(P->right != nullptr)
    P = P->right;
    dlptr T = P;
    P = P->left;
    P->right = nullptr;
    T->left = nullptr;
    free(T);
}

void Delete(dlptr &P, int k) {
    if(k == P->data) {
        Delete_front(P);
    } else {
        dlptr active, P1 = P;
        while(P1->right->data != k)
        P1 = P1->right;
        active = P1->right;
        P1->right = P1->right->right;
        active->right = nullptr;
        P1->right->right->left = P1;
        active->left = nullptr;
        free(active);
    }
}
bool isleft(dlptr l, dlptr h) {
    if(l == nullptr || h == nullptr || l == h)
    return false;
    while(l != nullptr) {
        if(l == h)
        return true;
        l = l->right;
    }
    return false;
}
dlptr partition(dlptr P, dlptr low, dlptr high) {
  int p = low->data;
  dlptr l = low->right;
  dlptr h = high;
  while(isleft(l, h)) {
    while(l->data < p) l = l->right;
    while(h->data > p) h = h->left;
    if(isleft(l, h)) {
        int temp = l->data;
        l->data = h->data;
        h->data = temp;
    }
  }
  int temp = low->data;
  low->data = h->data;
  h->data = temp;
  return h;
}
void quicksort(dlptr P, dlptr low, dlptr high) {
  if(isleft(low, high)) {
    dlptr k = partition(P, low, high);
    quicksort(P, low, k->left);
    quicksort(P, k->right, high);
  }
}
int main() {
    dlptr D1 = new(dlnode);
    int n, x, y;
    cin >> n;
    D1->data = n;
    D1->right = nullptr;
    D1->left = nullptr;
    cin >> n;
    while(n != -1) {
        insert(D1, n);
        cin >> n;
    }
    print(D1);
    cin >> n;
    Add_front(D1, n);
    print(D1);
    cin >> n;
    Add_End(D1, n);
    print(D1);
    cin >> x >> y;
    Add_before(D1, x, y);
    print(D1);
    cin >> x >> y;
    Add_after(D1, x, y);
    print(D1);
    Delete_front(D1);
    print(D1);
    Delete_End(D1);
    print(D1);
    cin >> n;
    Delete(D1, n);
    print(D1);
    dlptr E = D1;
    while(E->right != nullptr)
    E = E->right;
    quicksort(D1, D1, E);
    print(D1);
    return 0;
}
