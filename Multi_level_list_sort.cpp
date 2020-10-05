#include<iostream>
#include<cmath>
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
int min1(mlptr MT) {
    int min1 = 10000;
    while(MT != nullptr) {
        min1 = min(min1, MT->data);
        lptr T = MT->dlink;
        while(T != nullptr) {
            min1 = min(min1, T->data);
            T = T->next;
        }
        MT = MT->next;
    }
    return min1;
}
void place(mlptr MT, int num, int m1) {
    while(MT != nullptr) {
        if(MT->data == m1) {
            MT->data = num;
            return;
        }
        lptr T = MT->dlink;
        while(T != nullptr) {
            if(T->data == m1) {
                T->data = num;
                return;
            }
            T = T->next;
        }
        MT = MT->next;
    }
}
void sort_ll(mlptr ML) {
    while(ML != nullptr) {
        int num = ML->data;
        int m1 = min1(ML);
        if(num != m1) {
            place(ML, num, m1);
            ML->data = m1;
        }
        lptr L1, L = ML->dlink;
        while(L != nullptr) {
            num = L->data;
            m1 = min1(ML->next);
            L1 = L;
            while(L1 != nullptr) {
                m1 = min(m1, L1->data);
                L1 = L1->next;
            }
            if(num != m1) {
                place(ML, num, m1);
                L->data = m1;
            }
            L = L->next;
        }
        ML = ML->next;
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
    sort_ll(ML1);
    print(ML1);
}
