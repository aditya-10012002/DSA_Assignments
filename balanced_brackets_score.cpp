#include<iostream>
#include<string>
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
    return (S.top == -1)?-1:S.elements[S.top--];
}
int peek(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top];
}
int sum_till_index(int arr[], int m, int n) {
    int sum = 0;
    for(int i=m;i<n;i++) {
        sum += arr[i];
        arr[i] = 0;
    }
    return sum;
}

int main() {
    struct stack S1;
    S1.top = -1;
    S1.size = 50;
    cout << "Enter the balanced brackets expression\n";
    string s;
    getline(cin, s);
    int n = s.length();
    int arr[n];
    for(int i=0;i<n;i++)
    arr[i] = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == '(')
        push(S1, i);
        else {
            int p = pop(S1);
            int diff = i-p-1;
            if(diff == 0)
            arr[i] = 1;
            else {
                arr[i] = 2*sum_till_index(arr, p+1, i);
            }
        }
    }
    cout << sum_till_index(arr, 0, n) << endl;
    return 0;
}
