#include<iostream>
using namespace std;

struct btnode {
    btnode *lchild;
    int data;
    btnode *rchild;
};
typedef btnode *btptr;

void insert(btptr &T, int k) {
    if(T == nullptr) {
        T = new(btnode);
        T->data = k;
        T->lchild = nullptr;
        T->rchild = nullptr;
    }
    int ch;
    //cout << "Enter lchild child for " << k << endl;
    cin >> ch;
    if(ch != 0)
    insert(T->lchild, ch);
    //cout << "Enter rchild child for " << k << endl;
    cin >> ch;
    if(ch != 0)
    insert(T->rchild, ch);
}
bool checkBST(btptr root, int min, int max) {
    if(root == nullptr)
    return true;
    if(root->data < min || root->data > max)
    return false;
    return(checkBST(root->lchild, min, root->data-1) && checkBST(root->rchild, root->data+1, max));
}
bool checkBST(btptr root) {
    return checkBST(root, 0, 100000);
}
int main() {
    int ch;
    btptr B = nullptr;
    cin >> ch;
    insert(B, ch);
    checkBST(B)?cout << "Yes it is a binary tree\n":cout << "No it is not a binary tree\n";
    return 0;
}
