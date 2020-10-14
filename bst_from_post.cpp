#include<iostream>
#include<string>
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
    cout << endl;
    print_levelwise(Q);
}
int main() {
    int n;
    queue <bstptr> Q;
    bstptr T = nullptr;
    string s = "";
    cin >> n;
    while(n != -1) {
        s = to_string(n) + s;
        cin >> n;
    }
    for(int i=0;i<s.length();i++)
    insert(T, (int)(s[i]-'0'));
    Q.push(T);
    print_levelwise(Q);
    return 0;
}
