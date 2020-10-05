#include<iostream>
using namespace std;

struct mlnode {
    int tag;
    union {
        char cdata;
        mlnode *dlink;
    } data;
    mlnode *next;
};
typedef mlnode *mlptr;

void insert(mlptr ML, string s, int &index) {
    mlptr T;
    if(s[index] == '}' || s[index] == '#') {
        return;
    } else if(s[index] == '{') {
        T = new(mlnode);
        T->tag = 1;
        T->data.dlink = nullptr;
        T->next = nullptr;
    } else {
        T = new(mlnode);
        T->tag = 0;
        T->data.cdata = s[index];
        T->next = nullptr;
    }
    if(ML->tag == 1) {
        if(ML->data.dlink == nullptr) {
            ML->data.dlink = T;
            insert(ML->data.dlink, s, index+=1);
        }
        else
        ML->next = T;
    } else
    ML->next = T;
    if(ML->tag == 1 && ML->next == nullptr)
    insert(ML, s, index+=1);
    else
    insert(ML->next, s, index+=1);
}
void print(mlptr ML) {
    if(ML != nullptr) {
        if(ML->tag == 0) {
            cout << ML->data.cdata << " ";
        } else {
            cout << "{ ";
            print(ML->data.dlink);
        }
        print(ML->next);
    }
    else if(ML == nullptr)
    cout << "} ";
}
int main() {
    string s; int index=2;
    mlptr ML1 = new(mlnode);
    getline(cin, s);
    if(s[1] != '{')
    ML1->tag = 0;
    ML1->data.cdata = s[1];
    ML1->next = nullptr;
    insert(ML1, s, index);
    cout << "{ ";
    print(ML1);
    cout << endl;
}
