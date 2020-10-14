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
void print_all_paths(bstptr T, int arr[], int index, int &min, int &max, int &mine, int &maxe) {
    if(T == nullptr)
    return;
    arr[index] = T->data;
    if(T->lchild == nullptr && T->rchild == nullptr) {
        int sum=0, e=0;
        for(int i=0;i<=index;i++) {
            cout << arr[i] << " ";
            sum += arr[i];
            if(arr[i]%2 == 0)
            e++;
        }
        cout << endl;
        max = (max > sum)?max:sum;
        min = (min < sum)?min:sum;
        maxe = (maxe > e)?maxe:e;
        mine = (mine < e)?mine:e;
        return;
    }
    print_all_paths(T->lchild, arr, index+1, min, max, mine, maxe);
    print_all_paths(T->rchild, arr, index+1, min, max, mine, maxe);
}
void print_leftmost(bstptr T) {
    if(T == nullptr) {
        cout << endl;
        return;
    }
    cout << T->data << " ";
    (T->lchild != nullptr)?print_leftmost(T->lchild):print_leftmost(T->rchild);
}
void print_rightmost(bstptr T) {
    if(T == nullptr) {
        cout << endl;
        return;
    }
    cout << T->data << " ";
    (T->rchild != nullptr)?print_rightmost(T->rchild):print_rightmost(T->lchild);
}
void print_max_min(bstptr T, int arr[], int index, int k) {
    if(T == nullptr)
    return;
    arr[index] = T->data;
    if(T->lchild == nullptr && T->rchild == nullptr) {
        int sum = 0;
        for(int i=0;i<=index;i++)
        sum += arr[i];
        if(sum == k) {
            for(int i=0;i<=index;i++)
            cout << arr[i] << " ";
            cout << endl;
        }
        return;
    }
    print_max_min(T->lchild, arr, index+1, k);
    print_max_min(T->rchild, arr, index+1, k);
}
void print_maxe_mine(bstptr T, int arr[], int index, int k, bool &flag) {
    if(T == nullptr)
    return;
    arr[index] = T->data;
    if(T->lchild == nullptr && T->rchild == nullptr) {
        int e = 0;
        for(int i=0;i<=index;i++)
        if(arr[i]%2 == 0)
        e++;
        if(flag && e == k) {
            for(int i=0;i<=index;i++)
            cout << arr[i] << " ";
            cout << endl;
            flag = false;
        }
        return;
    }
    print_maxe_mine(T->lchild, arr, index+1, k, flag);
    print_maxe_mine(T->rchild, arr, index+1, k, flag);
}

int main() {
    int n;
    bstptr T = nullptr;
    cin >> n;
    bool flag = true;
    while(n != -1) {
        insert(T, n);
        cin >> n;
    }
    int arr[10];
    int min = 1000, max = 0, mine = 1000, maxe = 0;
    print_all_paths(T, arr, 0, min, max, mine, maxe);
    print_leftmost(T);
    print_rightmost(T);
    print_max_min(T, arr, 0, max);
    print_max_min(T, arr, 0, min);
    print_max_min(T, arr, 0, 22);
    print_maxe_mine(T, arr, 0, maxe, flag);
    flag = true;
    print_maxe_mine(T, arr, 0, mine, flag);
    return 0;
}
