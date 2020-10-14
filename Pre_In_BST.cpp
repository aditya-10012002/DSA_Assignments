#include<iostream>
#include<string>
using namespace std;

struct btnode {
    btnode *lchild;
    char data;
    btnode *rchild;
};
typedef btnode *btptr;
void insert(btptr &T, char k) {
    T = new(btnode);
    T->data = k;
    T->lchild = nullptr;
    T->rchild = nullptr;
}
int find(string inorder, char ch, int l, int h) {
    for(int i=l;i<=h;i++)
    if(inorder[i] == ch)
    return i;
    return -1;
}
void construction(btptr &T, string pre, string in, int low, int high, int &index) {
    if(low <= high) {
        int x = find(in, pre[index++], low, high);
        insert(T, in[x]);
        construction(T->lchild, pre, in, low, x-1, index);
        construction(T->rchild, pre, in, x+1, high, index);
    }
}
void print_postorder(btptr T) {
    if(T != nullptr) {
        print_postorder(T->lchild);
        print_postorder(T->rchild);
        cout << T->data << " ";
    }
}
int main() {
    int index = 0;
    string in, pre;
    btptr T = nullptr;
    cout << "Enter the preorder of the binary tree\n";
    cin >> pre;
    cout << "Enter the inorder\n";
    cin >> in;
    construction(T, pre, in, 0, in.length()-1, index);
    print_postorder(T);
    cout << endl;
    return 0;
}
