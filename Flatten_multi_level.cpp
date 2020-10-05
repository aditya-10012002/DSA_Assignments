#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
struct mlnode {
    int data;
    node *dlink;
    mlnode *next;
};
typedef mlnode *mlptr;
typedef node *lptr;

void insert(mlptr ML, int x, int tg) {
    while(ML->next != nullptr)
    ML = ML->next;
    if(tg == 0) {
        mlptr T = new(mlnode);
        T->data = x;
        T->dlink = nullptr;
        T->next = nullptr;
        ML->next = T;
    } else {
        lptr T = new(node);
        T->data = x;
        T->next = nullptr;
        if(ML->dlink == nullptr)
        ML->dlink = T;
        else {
            while(ML->dlink->next != nullptr)
            ML->dlink = ML->dlink->next;
            ML->dlink->next = T;
        }
    }
}
void print(mlptr ML) {
    while(ML != nullptr) {
        cout << ML->data << " ";
        lptr T = ML->dlink;
        while(T != nullptr) {
            cout << T->data << " ";
            T = T->next;
        }
        ML = ML->next;
    }
    cout << endl;
}
int main() {
    mlptr ML1;
    int n;
    ML1 = new(mlnode);
    cin >> n;
    ML1->data = n;
    ML1->dlink = nullptr;
    ML1->next = nullptr;
    cin >> n;
    while(n != -2) {
        if(n == 1) {
            cin >> n;
            if(n == -2)
            break;
            while(n != -1) {
                insert(ML1, n, 1);
                cin >> n;
            }
            cin >> n;
        } else if(n != 0) {
            insert(ML1, n, 0);
            cin >> n;
        } else {
            cin >> n;
        }
    }
    print(ML1);
}
