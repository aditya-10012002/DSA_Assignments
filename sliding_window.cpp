#include<iostream>
#include<cmath>
using namespace std;

struct stack {
    int size;
    int top;
    int elements[50];
};
void push(struct stack &S, int x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
int pop(struct stack &S) {
    return (S.top == -1)?-100:S.elements[S.top--];
}
int peek(struct stack &S) {
    return (S.top == -1)?-100:S.elements[S.top];
}
int main() {
    stack S1;
    S1.top = -1;
    S1.size = 50;
    cout << "Enter the array size and the window size\n";
    int n, m;
    cin >> n >> m;
    int arr[n];
    cout << "Enter the array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    int s = (n-m+1 > 0)?n-m+1:1;
    int c[s];
    for(int i=0;i<s;i++) {
        for(int j=i;j<i+min(m, n);j++) {
            if(arr[j] > peek(S1)) {
                pop(S1);
                push(S1, arr[j]);
            }
        }
        c[i] = pop(S1);
    }
    for(int i=0;i<s;i++)
    cout << c[i] << " ";
    cout << endl;
    return 0;
}
