//Benefit from  fit LL to set
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
typedef node *lptr;

void insert(lptr P, int num) {
    lptr T;
    T = new(node);
    T->data = num;
    T->next = nullptr;
    while(P->next != nullptr)
    P = P->next;
    P->next = T;
}
void Delete_front(lptr &P) {
    P = P->next;
}
void Delete(lptr &P, int k) {
    if(k == P->data) {
        Delete_front(P);
    } else {
        lptr active, T1 = P;
        while(P->next->data != k)
        P = P->next;
        active = P->next;
        P->next = P->next->next;
        active->next = nullptr;
        free(active);
        P = T1;
    }
}
void delete_duplicates(lptr &P) {
    lptr T1, T2;
    T1 = P;
    while(T1->next != nullptr) {
        T2 = T1;
        while(T2->next->data == T1->data) {
            T2 = T2->next;
            if(T2->next == nullptr)
            break;
        }
        while(T1 != T2) {
            T1 = T1->next;
            Delete(P, T2->data);
        }
        T1 = T1->next;
        if(T1 == nullptr) break;
    }
}
lptr Union(lptr P1, lptr P2) {
    lptr T, T1, T2;
    T = new(node);
    if(P1->data <= P2->data) {
        T->data = P1->data;
        P1 = P1->next;
    } else {
        T->data = P2->data;
        P2 = P2->next;
    }
    T->next = nullptr;

    while(P1 != nullptr && P2 != nullptr) {
        if(P1->data <= P2->data) {
            insert(T, P1->data);
            P1 = P1->next;
        } else {
            insert(T, P2->data);
            P2 = P2->next;
        }
    }
    while(P1 != nullptr) {
        insert(T, P1->data);
        P1 = P1->next;
    }
    while(P2 != nullptr) {
        insert(T, P2->data);
        P2 = P2->next;
    }
    delete_duplicates(T);
    return T;
}

int find(lptr P, int k) {
    while(P != NULL) {
        if(P->data == k)
        return 1;
        P = P->next;
    }
    return 0;
}

lptr U_union(lptr P1, lptr P2) {
    lptr T;
    T = new(node);
    T->data = P1->data;
    T->next = nullptr;
    P1 = P1->next;
    while(P1 != nullptr) {
        insert(T, P1->data);
        P1 = P1->next;
    }
    while(P2 != nullptr) {
        if(!find(T, P2->data))
        insert(T, P2->data);
        P2 = P2->next;
    }
    return T;
}

lptr Intersection(lptr P1, lptr P2) {
    lptr T1, T2, T3 = nullptr;
    T1 = P1;
    while(T1 != nullptr) {
        T2 = P2;
        while (T2 != nullptr) {
            if(T1->data == T2->data) {
                if(T3 == nullptr) {
                    T3 = new(node);
                    T3->data = T1->data;
                    T3->next = nullptr;
                } else {
                    insert(T3, T1->data);
                }
                break;
            }
            T2 = T2->next;
        }
        T1 = T1->next;
    }
    return T3;
}

lptr diff(lptr &P1, lptr P2) {
    lptr T = Intersection(P1, P2);
    while (T != nullptr) {
        Delete(P1, T->data);
        T = T->next;
    }
    return P1;
}



void print(lptr P) {
    /*if(P == nullptr)
    cout << "Its empty";
    else*/
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

int main() {
    lptr L1, L2, L3;
    int n;
    L1 = new(node);
    cin >> n;
    L1->data = n;
    L1->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L1, n);
        cin >> n;
    }

    L2 = new(node);
    cin >> n;
    L2->data = n;
    L2->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L2, n);
        cin >> n;
    }
    L3 = Union(L1, L2);
    print(L3);
    L3 = Intersection(L1, L2);
    print(L3);
    L3 = diff(L1, L2);
    print(L3);

    L1 = nullptr;
    L2 = nullptr;
    L1 = new(node);
    cin >> n;
    L1->data = n;
    L1->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L1, n);
        cin >> n;
    }

    L2 = new(node);
    cin >> n;
    L2->data = n;
    L2->next = nullptr;
    cin >> n;
    while(n != -1) {
        insert(L2, n);
        cin >> n;
    }
    L3 = U_union(L1, L2);
    print(L3);
    L3 = Intersection(L1, L2);
    print(L3);
    L3 = diff(L1, L2);
    print(L3);
    return 0;
}
