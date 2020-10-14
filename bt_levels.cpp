#include<iostream>
#include<queue>
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
    //cout << "Enter left child for " << k << endl;
    cin >> ch;
    if(ch != 0)
    insert(T->lchild, ch);
    //cout << "Enter right child for " << k << endl;
    cin >> ch;
    if(ch != 0)
    insert(T->rchild, ch);
}
void print_levelwise(queue <btptr> &Q, int &max, int &min, int prev, int &asf, int &dsf, int &l) {
    int s = Q.size();
    bool as=true, ds=true;
    if(s == 0)
    return;
    while(s-- > 0) {
        btptr P = Q.front();
        Q.pop();
        max = (max > P->data)?max:P->data;
        min = (min < P->data)?min:P->data;
        if(P->data < prev && prev != -1)
        as = false;
        if(P->data > prev && prev != -1)
        ds = false;
        prev = P->data;
        if(P->lchild != nullptr)
        Q.push(P->lchild);
        if(P->rchild != nullptr)
        Q.push(P->rchild);
    }
    if(as)
    asf++;
    if(ds)
    dsf++;
    l++;
    print_levelwise(Q, max, min, -1, asf, dsf, l);
}
int main() {
    int ch, min=1000, max=0, l=0, asf=0, dsf=0;
    queue <btptr> Q;
    btptr B = nullptr;
    //cout << "Enter the root\n";
    cin >> ch;
    insert(B, ch);
    Q.push(B);
    print_levelwise(Q, max, min, -1, asf, dsf, l);
    cout << max << endl << min << endl << --asf << endl << dsf << endl << (l-asf-dsf+2) << endl;
    return 0;
}
