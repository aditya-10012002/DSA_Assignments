#include<iostream>
#include<cmath>
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

void add(lptr L1, lptr L2, lptr L3) {
    if(L1 != nullptr && L2 != nullptr) {
        add(L1->next, L2->next, L3->next);
        int num = L1->data + L2->data;
        int c = num/10;
        num = num - 10*c;
        L3->next->data += num;
        L3->data += c;
    }
}

void print(lptr P) {
    if(P->data == 0)
    P = P->next;
    while(P != nullptr) {
        cout << P->data;
        P = P->next;
    }
    cout << endl;
}
int main() {
    lptr L1, L2, L3;
    string s;
    L1 = new(node);
    cin >> s;
    L1->data = s[0] - '0';
    L1->next = nullptr;
    int n = s.length();
    for(int i=1;i<n;i++) {
        insert(L1, s[i]-'0');
    }
    L2 = new(node);
    cin >> s;
    L2->data = s[0]-'0';
    L2->next = nullptr;
    n = s.length();
    for(int i=1;i<n;i++) {
        insert(L2, s[i]-'0');
    }
    L3 = new(node);
    L3->data = 0;
    L3->next = nullptr;
    int c = max(count_nodes(L1), count_nodes(L2));
    while(c-- > 0) {
        insert(L3, 0);
    }
    add(L1, L2, L3);
    print(L3);
    return 0;
}
