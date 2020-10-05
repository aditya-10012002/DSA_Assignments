#include<iostream>
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
int area(int arr[], int n) {
    int max = 0;
    for(int i=0;i<n;i++) {
        int count = 1;
        for(int j=i-1;j>=0;j--)
        if(arr[j] >= arr[i])
        count++;
        for(int j=i+1;j<n;j++)
        if(arr[j] >= arr[i])
        count++;
        int value = count*arr[i];
        max = (max < value)?value:max;
    }
    return max;
}
int area_with_stacks(int arr[], int n) {
    struct stack S1;
    S1.top = -1;
    S1.size = 50;
    int max = 0;
    for(int i=0;i<n;i++) {
        int j=0;
        while(arr[i] < arr[peek(S1)] && peek(S1) != -1) {
            j = pop(S1);
            int area1 = arr[j]*(i-j);
            max = (max > area1)?max:area1;
        }
        push(S1, i);
    }
    return max;
}
int main() {
    int n;
    cout << "Enter the size of the array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    cout << "Maximum area computed without stacks " << area(arr, n) << endl;
    cout << "Maximum area computed with stacks " << area_with_stacks(arr, n) << endl;
    return 0;
}
