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
    } else {
        (k < T->data)?insert(T->lchild, k):insert(T->rchild, k);
    }
}
void print_preorder(bstptr T) {
    if(T != nullptr) {
        cout << T->data << " ";
        print_preorder(T->lchild);
        print_preorder(T->rchild);
    }
}
void print_inorder(bstptr T) {
    if(T != nullptr) {
        print_inorder(T->lchild);
        cout << T->data << " ";
        print_inorder(T->rchild);
    }
}
void print_postorder(bstptr T) {
    if(T != nullptr) {
        print_postorder(T->lchild);
        print_postorder(T->rchild);
        cout << T->data << " ";
    }
}
void print_levelwise(queue <bstptr> &Q) {
    int s = Q.size();
    if(s == 0)
    return;
    while(s-- > 0) {
        bstptr P = Q.front();
        Q.pop();
        cout << P->data << " ";
        if(P->lchild != nullptr)
        Q.push(P->lchild);
        if(P->rchild != nullptr)
        Q.push(P->rchild);
    }
    print_levelwise(Q);
}
int find_min(bstptr T) {
    if(T->lchild == nullptr)
    return T->data;
    return find_min(T->lchild);
}
int find_max(bstptr T) {
    if(T->rchild == nullptr)
    return T->data;
    return find_max(T->rchild);
}
int main() {
    int n;
    queue <bstptr> Q;
    bstptr T = nullptr;
    cout << "Enter the values to be input in bst\n";
    cin >> n;
    while(n != -1) {
        insert(T, n);
        cin >> n;
    }
    cout << "Preorder: ";
    print_preorder(T);
    cout << "\nInorder: ";
    print_inorder(T);
    cout << "\nPostorder: ";
    print_postorder(T);
    cout << "\nLevelorder: ";
    Q.push(T);
    print_levelwise(Q);
    cout << "\nMinimum element " << find_min(T) << endl;
    cout << "Maximum element " << find_max(T) << endl;
    return 0;
}
