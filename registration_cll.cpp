#include<iostream>
using namespace std;

struct rnode;
struct snode {
    int rno;
    rnode *vlink;
};
struct cnode {
    char cname;
    rnode *hlink;
};
struct rnode {
    int tg1;
    union {
        rnode *snext;
        snode *dnext;
    } cinfo;
    int tg2;
    union {
        rnode *snext;
        cnode *dnext;
    } sinfo;
};
typedef snode *sptr;
typedef cnode *cptr;
typedef rnode *rptr;

void insert(sptr S[], cptr C[], int sn) {
    int k;
    char ch;
    cin >> k;
    cin >> ch;
    while(k != -1) {
        rptr T = new(rnode);
        if(S[k-1]->vlink == nullptr) {
            S[k-1]->vlink = T;
            T->cinfo.dnext = S[k-1];
            T->tg1 = 1;
        } else {
            rptr L1, L = S[k-1]->vlink;
            while(true) {
                L1 = L;
                while(L1->tg2 == 0)
                L1 = L1->sinfo.snext;
                if(ch < L1->sinfo.dnext->cname || L->tg1 == 1)
                break;
                L = L->cinfo.snext;
            }
            if(ch < L1->sinfo.dnext->cname) {
                L1 = S[k-1]->vlink;
                if(L1 == L) {
                    T->tg1 = 0;
                    T->cinfo.snext = L;
                    S[k-1]->vlink = T;
                } else {
                    while(L1->cinfo.snext != L)
                    L1 = L1->cinfo.snext;
                    T->tg1 = 0;
                    T->cinfo.snext = L;
                    L1->cinfo.snext = T;
                }
            } else {
                L1 = S[k-1]->vlink;
                if(L1 == L) {
                    T->tg1 = 1;
                    T->cinfo.dnext = S[k-1];
                    L1->cinfo.snext = T;
                    L->tg1 = 0;
                } else {
                    T->tg1 = 1;
                    T->cinfo.dnext = S[k-1];
                    L->cinfo.snext = T;
                    L->tg1 = 0;
                }
            }
        }

        if(C[ch-'A']->hlink == nullptr) {
            C[ch-'A']->hlink = T;
            T->sinfo.dnext = C[ch-'A'];
            T->tg2 = 1;
        } else {
            rptr L1, L = C[ch-'A']->hlink;
            while(true) {
                L1 = L;
                while(L1->tg1 == 0)
                L1 = L1->cinfo.snext;
                if(k < L1->cinfo.dnext->rno || L->tg2 == 1)
                break;
                L = L->sinfo.snext;
            }
            if(k < L1->cinfo.dnext->rno) {
                L1 = C[ch-'A']->hlink;
                if(L1 == L) {
                    T->tg2 = 0;
                    T->sinfo.snext = L;
                    C[ch-'A']->hlink = T;
                } else {
                    while(L1->sinfo.snext != L)
                    L1 = L1->sinfo.snext;
                    T->tg2 = 0;
                    T->sinfo.snext = L;
                    L1->sinfo.snext = T;
                }
            } else {
                L1 = C[ch-'A']->hlink;
                if(L1 == L) {
                    T->tg2 = 1;
                    T->sinfo.dnext = C[ch-'A'];
                    L1->sinfo.snext = T;
                    L->tg2 = 0;
                } else {
                    T->tg2 = 1;
                    T->sinfo.dnext = C[ch-'A'];
                    L->sinfo.snext = T;
                    L->tg2 = 0;
                }
            }
        }
        cin >> k;
        cin >> ch;
    }
}
void print_C(sptr S[], cptr C[], int x) {
    rptr T = S[x-1]->vlink;
    while(true) {
        rptr L = T;
        while(L->tg2 == 0)
        L = L->sinfo.snext;
        cout << L->sinfo.dnext->cname << " ";
        if(T->tg1 == 1)
        break;
        T = T->cinfo.snext;
    }
    cout << endl;
}
void print_S(sptr S[], cptr C[], char ch) {
    rptr T = C[ch-'A']->hlink;
    while(true) {
        rptr L = T;
        while(L->tg1 == 0)
        L = L->cinfo.snext;
        cout << L->cinfo.dnext->rno << " ";
        if(T->tg2 == 1)
        break;
        T = T->sinfo.snext;
    }
    cout << endl;
}
int main() {
    int x; char ch;
    sptr S1[5];
    cptr C1[4];
    for(int i=0;i<5;i++) {
        S1[i] = new(snode);
        S1[i]->rno = i+1;
        S1[i]->vlink = nullptr;
    }
    for(int i=0;i<4;i++) {
        C1[i] = new(cnode);
        C1[i]->cname = (char)(65+i);
        C1[i]->hlink = nullptr;
    }
    insert(S1, C1, 5);
    cin >> x;
    print_C(S1, C1, x);
    cin >> ch;
    print_S(S1, C1, ch);
    return 0;
}
