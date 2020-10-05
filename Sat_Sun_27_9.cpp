#include<iostream>
using namespace std;

struct mnode {
    int data;
    mnode *next[2];
};
typedef mnode *mptr;

void insert(mptr &M) {
    int x, y, z;
    cin >> x >> y >> z;
    if(y == 0)
    return;
    else if(M == nullptr) {
        M = new(mnode);
        M->data = x;
        for(int i=0;i<2;i++)
        M->next[i] = nullptr;
        mptr T = new(mnode);
        T->data = y;
        for(int i=0;i<2;i++)
        T->next[i] = nullptr;
        M->next[0] = T;
        if(z != 0) {
            T = new(mnode);
            T->data = z;
            for(int i=0;i<2;i++)
            T->next[i] = nullptr;
            M->next[1] = T;
        }
        insert(M->next[0]);
    } else {
        mptr T;
        if(M->next[0] == nullptr) {
            T = new(mnode);
            T->data = y;
            for(int i=0;i<2;i++)
            T->next[i] = nullptr;
            M->next[0] = T;
        }
        if(z != 0) {
            T = new(mnode);
            T->data = z;
            for(int i=0;i<2;i++)
            T->next[i] = nullptr;
            M->next[0]->next[0] = T;
            M->next[1] = T;
        }
        insert(M->next[0]);
    }
}
void print(int path[], int n) {
    for(int i=0;i<n;i++)
    cout << path[i] << " ";
    cout << endl;
}
void print_paths(mptr M, int path[], int index) {
    path[index] = M->data;
    if(M->next[0] == nullptr && M->next[1] == nullptr) {
        print(path, index+1);
        return;
    }
    for(int i=0;i<2;i++) {
        if(M->next[i] != nullptr) {
            print_paths(M->next[i], path, index+1);
        }
    }
}
int main() {
    mptr M1 = nullptr;
    insert(M1);
    int path[50];
    print_paths(M1, path, 0);
    return 0;
}
