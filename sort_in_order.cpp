#include<iostream>
using namespace std;

void sort(int arr1[], int index, int m) {
    for (int i = index; i < m-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < m; j++)
        if (arr1[j] < arr1[min_idx])
            min_idx = j;
        swap(arr1[min_idx], arr1[i]);
    }
}
void inorder(int arr1[], int arr2[], int m, int n) {
    int in = 0;
    for(int i=0;i<n;i++) {
        for(int j=in;j<m;j++) {
            if(arr2[i] == arr1[j])
            swap(arr1[in++], arr1[j]);
        }
    }
    sort(arr1, in, m);
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
    inorder(arr1, arr2, m, n);
    cout << "Sorted array\n";
    for(int i=0;i<m;i++)
    cout << arr1[i] << " ";
    cout << endl;
    return 0;
}
