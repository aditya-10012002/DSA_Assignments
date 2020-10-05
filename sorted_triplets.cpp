#include<iostream>
using namespace std;
void print(int a[]) {
    for(int i=0;i<3;i++)
    cout << a[i] << " ";
    cout << endl;
}
bool flag;
void sortedtriplets(int arr[], int c, int a[], int index, int n) {
    if(c == 3) {
        print(a);
        flag = false;
        return;
    }
    else {
        for(int i=index;i<n && flag;i++) {
            if(c == 0) {
                a[c] = arr[i];
                sortedtriplets(arr, c+1, a, i+1, n);
            }
            else if(a[c-1] < arr[i]) {
                a[c] = arr[i];
                sortedtriplets(arr, c+1, a, i+1, n);
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter the array size\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    int a[3];
    flag = true;
    sortedtriplets(arr, 0, a, 0, n);
    return 0;
}
