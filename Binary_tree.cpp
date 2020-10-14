#include<iostream>
using namespace std;

struct btnode {
    btnode *lchild;
    char data;
    btnode *rchild;
};
typedef btnode *btptr;

void insert(btptr &T, char k) {
    if(T == nullptr) {
        T = new(btnode);
        T->data = k;
        T->lchild = nullptr;
        T->rchild = nullptr;
    }
    char ch;
    //cout << "Enter left child for " << k << endl;
    cin >> ch;
    if(ch != '.')
    insert(T->lchild, ch);
    //cout << "Enter right child for " << k << endl;
    cin >> ch;
    if(ch != '.')
    insert(T->rchild, ch);
}
void print(btptr T) {
    if(T == nullptr) {
        cout << ".";
        return;
    }
    cout << T->data;
    print(T->lchild);
    print(T->rchild);
}
int main() {
    char ch;
    btptr B = nullptr;
    //cout << "Enter the root\n";
    cin >> ch;
    insert(B, ch);
    print(B);
    cout << endl;
    return 0;
}
