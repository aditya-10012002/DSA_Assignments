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
void print_levelwise(int arr[], int index, queue <bstptr> &Q) {
    int s = Q.size();
    if(s == 0) {
        cout << endl;
        for(int i=index-1;i>=0;i--)
        cout << arr[i] << " ";
        cout << endl;
        return;
    }
    while(s-- > 0) {
        bstptr P = Q.front();
        Q.pop();
        arr[index++] = P->data;
        cout << P->data << " ";
        if(P->lchild != nullptr)
        Q.push(P->lchild);
        if(P->rchild != nullptr)
        Q.push(P->rchild);
    }
    print_levelwise(arr, index, Q);
}
void print_levelwise_reverse(int arr[], int index, queue <bstptr> &Q) {
    int s = Q.size();
    if(s == 0) {
        for(int i=index-1;i>=0;i--)
        cout << arr[i] << " ";
        cout << endl;
        return;
    }
    while(s-- > 0) {
        bstptr P = Q.front();
        Q.pop();
        arr[index++] = P->data;
        if(P->rchild != nullptr)
        Q.push(P->rchild);
        if(P->lchild != nullptr)
        Q.push(P->lchild);
    }
    print_levelwise_reverse(arr, index, Q);
}
void print_squirrel_clock(int arr[], int index, int f, queue <bstptr> &Q) {
    int s1, i=0, s = Q.size();
    s1 = s;
    if(s == 0) {
        for(i=0;i<index;i++)
        cout << arr[i] << " ";
        cout << endl;
        return;
    }
    while(s-- > 0) {
        bstptr P = Q.front();
        Q.pop();
        if(f == 0)
        arr[index+s-i] = P->data;
        else
        arr[index+i++] = P->data;
        if(P->lchild != nullptr)
        Q.push(P->lchild);
        if(P->rchild != nullptr)
        Q.push(P->rchild);
    }
    print_squirrel_clock(arr, index+s1, (f==1)?0:1, Q);
}
int main() {
    int n;
    queue <bstptr> Q;
    bstptr T = nullptr;
    cin >> n;
    while(n != -1) {
        insert(T, n);
        cin >> n;
    }
    int arr[10];
    Q.push(T);
    print_levelwise(arr, 0, Q);
    Q.push(T);
    print_levelwise_reverse(arr, 0, Q);
    Q.push(T);
    print_squirrel_clock(arr, 0, 1, Q);
    Q.push(T);
    print_squirrel_clock(arr, 0, 0, Q);
    Q.push(T);
    print_squirrel_clock(arr, 0, 1, Q);
    Q.push(T);
    print_squirrel_clock(arr, 0, 0, Q);
    return 0;
}
