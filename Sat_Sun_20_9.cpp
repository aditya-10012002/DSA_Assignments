/*
Week days   are   working  days
Weekends    are   hard  working  days for 'Winners' */
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

int count_nodes(lptr P) {
    int c=0;
    while(P != nullptr) {
        c++;
        P = P->next;
    }
    return c;
}

void Delete_front(lptr &P) {
    lptr active = P;
    P = P->next;
    active->next = nullptr;
    free(active);
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

void Delete_pos(lptr &P, int pos) {
    if(pos == 0) {
        Delete_front(P);
    } else {
        lptr active, T1 = P;
        while(pos-- > 1)
        P = P->next;
        active = P->next;
        P->next = P->next->next;
        active->next = nullptr;
        free(active);
        P = T1;
    }
}

bool palindrome(lptr P) {
    lptr T;
    int c = count_nodes(P);
    int pos = c/2 + c%2;
    for(int i=0;i<pos;i++) {
        T = P;
        for(int j=0;j<c-1;j++)
        T = T->next;
        if(T->data != P->data)
        return false;
        c -= 2;
        P = P->next;
    }
    return true;
}

void rem_duplicates_sorted(lptr &P) {
    if(P->next != nullptr) {
        if(P->data == P->next->data) {
            Delete(P, P->data);
            rem_duplicates_sorted(P);
        } else {
            rem_duplicates_sorted(P->next);
        }
    }
}

void rem_duplicates_unsorted(lptr &P) {
    lptr T1 = P, T2;
    int num, n = count_nodes(P);
    for(int i=0;i<n-1;i++) {
        num = T1->data;
        T2 = T1->next;
        for(int j=i+1;j<n;j++) {
            if(T2->data == num) {
                T2 = T2->next;
                Delete_pos(P, j);
                n--;
            } else
            T2 = T2->next;
        }
        T1 = T1->next;
    }
}

void rem_last_duplicate(lptr &P) {
    lptr T1 = P, T2;
    int num, pos, n = count_nodes(P);
    for(int i=0;i<n-1;i++) {
        num = T1->data;
        T2 = T1->next;
        pos = -1;
        for(int j=i+1;j<n;j++) {
            if(T2->data == num) {
                T2 = T2->next;
                pos = j;
            } else
            T2 = T2->next;
        }
        if(pos != -1) {
            Delete_pos(P, pos);
            n--;
        }
        T1 = T1->next;
    }
}

void even_odd(lptr P) {
    lptr T1, T2;
    int temp, temp1;
    while(P->next != nullptr) {
        if(P->data%2 != 0) {
            T1 = P->next;
            while(T1 != nullptr && T1->data%2 != 0) {
                T1 = T1->next;
            }
            if(T1 == nullptr)
            break;
            T2 = P;
            temp = T2->data;
            T2->data = T1->data;
            T2 = T2->next;
            while(T1 != T2) {
                temp1 = T2->data;
                T2->data = temp;
                temp = temp1;
                T2 = T2->next;
            }
            T1->data = temp;
        }
        P = P->next;
    }
}

void Add_front(lptr &P, int k) {
    lptr T;
    T = new(node);
    T->data = k;
    T->next = P;
    P = T;
}

void Add_before(lptr &P, int x, int y) {
    lptr T;
    T = new(node);
    T->data = x;
    if(y == P->data) {
        Add_front(P, x);
    } else {
        lptr T1 = P;
        while(P->next->data != y)
        P = P->next;
        T->next = P->next;
        P->next = T;
        P = T1;
    }
}
void insertion_sort(lptr &P) {
    lptr T1 = P;
    int data;
    while(T1->next != nullptr) {
        if(T1->next->data < T1->data) {
            data = T1->next->data;
             Delete(P, T1->next->data);
            Add_before(P, data, T1->data);
        }
        T1 = T1->next;
    }
}

void rev(lptr &P1, lptr T1) {
    if(T1 != nullptr) {
        rev(P1, T1->next);
        P1->data = T1->data;
        P1 = P1->next;
    }
}
void reverse(lptr P) {
    int i=1, j = count_nodes(P);
    lptr T, P1=P;
    T = new(node);
    j -= i;
    while(i-- > 1) {
        P = P->next;
        P1 = P1->next;
    }
    T->data = P1->data;
    T->next = nullptr;

    while(j-- > 0) {
        P1 = P1->next;
        insert(T, P1->data);
    }
    rev(P, T);
}

void swap_nodes(lptr P, int k) {
    lptr T1, T2;
    T1 = P;
    for(int i=1;i<k;i++)
    T1 = T1->next;
    int n = count_nodes(P)-k+1;
    T2 = P;
    for(int i=1;i<n;i++)
    T2 = T2->next;
    int temp = T1->data;
    T1->data = T2->data;
    T2->data = temp;
}

int check_present(lptr P1, lptr P2) {
    lptr T1=P1, T2=P2;
    int c=0;
    while(P1 != nullptr) {
        if(P2->data != P1->data)
        P1 = P1->next;
        else {
            T2 = P2;
            T1 = P1;
            c=0;
            while(T2 != nullptr && T1->data == T2->data) {
                c++;
                T1 = T1->next;
                T2 = T2->next;
            }
            if(c == count_nodes(P2))
            return 1;
            P1 = P1->next;
        }
    }
    return 0;
}

lptr merge(lptr L1, lptr L2) {
    lptr L3;
    L3 = new(node);
    L3->data = L1->data;
    L3->next = nullptr;
    insert(L3, L2->data);
    L1 = L1->next;
    L2 = L2->next;
    while(L1 != nullptr && L2 != nullptr) {
        insert(L3, L1->data);
        insert(L3, L2->data);
        L1 = L1->next;
        L2 = L2->next;
    }
    while(L1 != nullptr) {
        insert(L3, L1->data);
        L1 = L1->next;
    }
    while(L2 != nullptr) {
        insert(L3, L2->data);
        L2 = L2->next;
    }
    return L3;
}

void print(lptr P) {
    while(P != nullptr) {
        cout << P->data << " ";
        P = P->next;
    }
    cout << endl;
}

lptr make_list(lptr L1) {
    L1 = nullptr;
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
    return L1;
}

int main() {
    lptr L1, L2;
    int k;

    /*L1 = make_list(L1);
    cout << palindrome(L1) << endl;

    L1 = make_list(L1);
    rem_duplicates_sorted(L1);
    print(L1);

    L1 = make_list(L1);
    rem_duplicates_unsorted(L1);
    print(L1);

    L1 = make_list(L1);
    rem_last_duplicate(L1);
    print(L1);

    L1 = make_list(L1);
    even_odd(L1);
    print(L1);*/

    L1 = make_list(L1);
    insertion_sort(L1);
    print(L1);

    /*L1 = make_list(L1);
    reverse(L1);
    print(L1);

    L1 = make_list(L1);
    cin >> k;
    swap_nodes(L1, k);
    print(L1);

    L1 = make_list(L1);
    L2 = make_list(L2);
    cout << check_present(L1, L2) << endl;

    L1 = make_list(L1);
    L2 = make_list(L2);
    lptr L3 = merge(L1, L2);
    print(L3);*/

    return 0;
}
