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
void print_triplet(dlptr P, int k) {
    dlptr D=P, E=P;
    while(E->right != nullptr)
    E = E->right;
    while(D->right != nullptr) {
        dlptr L=P, H=E;
        if(L == D)
        L = L->right;
        if(H == D)
        H = H->left;
        int sum = k - 2*D->data;
        while(L != H && L->left != H) {
            if(L->data + H->data == sum) {
                if(L != D && H != D)
                cout << D->data << " " << L->data << " " << H->data << endl;
                L = L->right;
                H = H->left;
            } else if(L->data + H->data > sum) {
                H = H->left;
            } else {
                L = L->right;
            }
        }
        D = D->right;
    }
}
int main() {
    dlptr D1 = new(dlnode);
    int n;
    cin >> n;
    D1->data = n;
    D1->right = nullptr;
    D1->left = nullptr;
    cin >> n;
    while(n != -1) {
        insert(D1, n);
        cin >> n;
    }
    cin >> n;
    print_triplet(D1, n);
    return 0;
}
