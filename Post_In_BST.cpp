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
void construction(btptr &T, string in, string post, int low, int high, int &index) {
    if(low <= high) {
        int x = find(in, post[index--], low, high);
        insert(T, in[x]);
        construction(T->rchild, in, post, x+1, high, index);
        construction(T->lchild, in, post, low, x-1, index);
    }
}
void print_preorder(btptr T) {
    if(T != nullptr) {
        cout << T->data << " ";
        print_preorder(T->lchild);
        print_preorder(T->rchild);
    }
}
int main() {
    string in, post;
    btptr T = nullptr;
    cout << "Enter the Inorder of the binary tree\n";
    cin >> in;
    cout << "Enter the Postorder\n";
    cin >> post;
    int index = in.length()-1;
    construction(T, in, post, 0, in.length()-1, index);
    print_preorder(T);
    cout << endl;
    return 0;
}
