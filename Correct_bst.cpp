#include<iostream>
#include<queue>
using namespace std;

struct bstnode {
    bstnode *lchild;
    int data;
    bstnode *rchild;
};
typedef bstnode *bstptr;
void insert(bstptr &T, int k) {
    if(T == nullptr) {
        T = new(bstnode);
        T->data = k;
        T->lchild = nullptr;
        T->rchild = nullptr;
    }
    int ch;
    cin >> ch;
    if(ch != 0)
    insert(T->lchild, ch);
    if(ch != 0)
    insert(T->rchild, ch);
}
void checkBST(bstptr T, int min, int max, bstptr S1, bstptr S2) {
    if(T == nullptr)
    return;
    if(T->data < min || T->data > max) {
        if(S1 == nullptr)
        S1 = T;
        else
        S2 = T;
        if(S1 != nullptr && S2 != nullptr) {
            int temp = S1->data;
            S1->data = S2->data;
            S2->data = temp;
        }
        return;
    }
    checkBST(T->lchild, min, T->data-1, S1, S2);
    checkBST(T->rchild, T->data+1, max, S1, S2);
}
void print_inorder(bstptr T) {
    if(T != nullptr) {
        print_inorder(T->lchild);
        cout << T->data << " ";
        print_inorder(T->rchild);
    }
}
int main() {
    int ch;
    bstptr S1=nullptr, S2=nullptr, T=nullptr;
    cin >> ch;
    insert(T, ch);
    checkBST(T, 0, 1000, S1, S2);
    print_inorder(T);
    cout << endl;
    return 0;
}
