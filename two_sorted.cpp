#include<iostream>
using namespace std;

void insertion(int arr2[], int num, int n) {
    int i=0;
    for(i=0;i<n-1;i++) {
        if(num < arr2[i+1]) {
            arr2[i] = num;
            return;
        } else {
            arr2[i] = arr2[i+1];
        }
    }
    arr2[n-1] = num;
}
void twosorted(int arr1[], int arr2[], int m, int n) {
    int i1=1;
    while(i1 < m) {
        if(arr1[i1] >= arr2[0]) {
            int t = arr1[i1];
            arr1[i1] = arr2[0];
            insertion(arr2, t, n);
        }
        i1++;
    }
}

int main() {
    int m, n;
    cout << "Enter the size of both arrays\n";
    cin >> m >> n;
    int arr1[m];
    int arr2[n];
    cout << "Enter the array elements of 1st array\n";
    for(int i=0;i<m;i++)
    cin >> arr1[i];
    cout << "Enter the array elements of 2nd array\n";
    for(int i=0;i<n;i++)
    cin >> arr2[i];
    twosorted(arr1, arr2, m, n);
    cout << "Sorted array\n";
    for(int i=0;i<m;i++)
    cout << arr1[i] << " ";
    cout << endl;
    for(int i=0;i<n;i++)
    cout << arr2[i] << " ";
    cout << endl;
    return 0;
}
