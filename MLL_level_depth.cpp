#include<iostream>
using namespace std;

struct mlnode {
    int data;
    mlnode *dlink;
    mlnode *next;
};
typedef mlnode *mlptr;

void insert(mlptr &ML, int n) {
    if(n == -1)
    return;
    if(n == 1) {
        cin >> n;
        mlptr T = new(mlnode);
        T->data = n;
        T->dlink = nullptr;
        T->next = nullptr;
        ML->dlink = T;
        cin >> n;
        insert(ML->dlink, n);
    } if(n == 0) {
        cin >> n;
        if(n == -1)
        return;
        insert(ML, n);
    }
    mlptr T = new(mlnode);
    T->data = n;
    T->dlink = nullptr;
    T->next = nullptr;
    ML->next = T;
    cin >> n;
    insert(ML->next, n);
}
int main() {
    int n;
    mlptr ML1 = new(mlnode);
    cin >> n;
    ML1->data = n;
    ML1->dlink = nullptr;
    ML1->next = nullptr;
    cin >> n;
    insert(ML1, n);
    return 0;
}
