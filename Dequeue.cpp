#include<iostream>
using namespace std;

struct Dequeue {
    int f;
    int r;
    int size;
    int elements[50];
};

void push_front(Dequeue &DQ, int num) {
    if((DQ.r+1)%DQ.size == DQ.f) {
        cout << "Dequeue is full\n";
    }
    else {
        if(DQ.f == -1) {
            DQ.f = 0;
            DQ.r = 0;
        } else {
            DQ.f = (DQ.size+DQ.f-1)%DQ.size;
        }
        DQ.elements[DQ.f] = num;
    }
}

void push_rear(Dequeue &DQ, int num) {
    if((DQ.r+1)%DQ.size == DQ.f) {
        cout << "Dequeue is full\n";
    }
    else {
        if(DQ.f == -1) {
            DQ.f = 0;
            DQ.r = 0;
        } else {
            DQ.r = (DQ.r+1)%DQ.size;
        }
        DQ.elements[DQ.r] = num;
    }
}

int pop_front(Dequeue &DQ) {
    int k;
    if(DQ.f == -1) {
        cout << "Dequeue is empty\n";
        k = -1;
    } else {
        if(DQ.f == DQ.r) {
            k = DQ.elements[DQ.f];
            DQ.f = -1;
            DQ.r = -1;
        } else {
            k = DQ.elements[DQ.f];
            DQ.f = (DQ.f+1)%DQ.size;
        }
    }
    return k;
}

int pop_rear(Dequeue &DQ) {
    int k;
    if(DQ.f == -1) {
        cout << "Dequeue is empty\n";
        k = -1;
    } else {
        if(DQ.f == DQ.r) {
            k = DQ.elements[DQ.f];
            DQ.f = -1;
            DQ.r = -1;
        } else {
            k = DQ.elements[DQ.r];
            DQ.r = (DQ.size+DQ.r-1)%DQ.size;
        }
    }
    return k;
}

int main() {
    Dequeue DQ1;
    DQ1.f = -1;
    DQ1.r = -1;
    DQ1.size = 50;

    while(true) {
        int ch;
        cout << "Enter 1 to restrict input from front, 2 to restrict output from rear, -1 to quit\n";
        cin >> ch;
        if(ch == -1)
        return 0;
        else if(ch == 1) {
            while(true) {
                int t;
                cout << "Enter 1 to enqueue, 2 to pop from front, 3 to pop from rear, -1 to quit\n";
                cin >> t;
                if(t == -1)
                break;
                switch(t) {
                    case 1: {
                        cout << "Enter the number\n";
                        int num;
                        cin >> num;
                        push_rear(DQ1, num);
                        break;
                    }
                    case 2:
                        cout << pop_front(DQ1) << endl;
                        break;
                    case 3:
                        cout << pop_rear(DQ1) << endl;
                        break;
                }
            }
        } else {
            while(true) {
                int t;
                cout << "Enter 1 to push from front, 2 to push from rear, 3 to dequeue, -1 to quit\n";
                cin >> t;
                if(t == -1)
                break;
                switch(t) {
                    case 1: {
                        cout << "Enter the number\n";
                        int num;
                        cin >> num;
                        push_front(DQ1, num);
                        break;
                    }
                    case 2: {
                        cout << "Enter the number\n";
                        int num;
                        cin >> num;
                        push_rear(DQ1, num);
                        break;
                    }
                    case 3:
                        cout << pop_front(DQ1) << endl;
                        break;
                }
            }
        }
    }
    return 0;
}
