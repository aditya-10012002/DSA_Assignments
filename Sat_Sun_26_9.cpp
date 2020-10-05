#include<iostream>
using namespace std;

struct mnode {
    int data;
    int cnt;
    mnode *next[3];
};
typedef mnode *mptr;

void insert(mptr M) {
    int n, f, j;
    cin >> n >> f;
    mptr T = new(mnode);
    T->data = n;
    T->cnt = f;
    for(int i=0;i<3;i++)
    T->next[i] = nullptr;
    for(j=0;j<M->cnt;j++)
    if(M->next[j] == nullptr)
    break;
    M->next[j] = T;
    M = M->next[j];
    for(j=0;j<f;j++)
    insert(M);
}
void print_range(int path[], int t) {
    for(int i=0;path[i] != t;i++)
    cout << path[i] << " ";
    cout << t << endl;
}
void print_des(mptr M, int path[], int index, bool flag, int s, int t) {
    if(M->data == t) {
        path[index] = M->data;
        print_range(path, t);
        return;
    }
    if(flag || M->data == s) {
        if(M->data == s)
        index=0; flag = true;
        path[index] = M->data;
    }
    for(int i=0;i<3;i++) {
        if(M->next[i] != nullptr)
        print_des(M->next[i], path, index+1, flag, s, t);
    }
}
void print(mptr M) {
    cout << M->data << " ";
    for(int i=0;i<3;i++) {
        if(M->next[i] != nullptr)
        print(M->next[i]);
    }
}
int main() {
    int s, t, f;
    mptr M1 = new(mnode);
    cin >> s >> f;
    M1->data = s;
    M1->cnt = f;
    for(int i=0;i<3;i++)
    M1->next[i] = nullptr;
    insert(M1);
    /*print(M);
    cout << endl;*/
    f=2; int path[50];
    while(f-- > 0) {
        cin >> s >> t;
        print_des(M1, path, 0, false, s, t);
    }
    return 0;
}
