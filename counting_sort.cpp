#include<iostream>
using namespace std;

void count_sort(int arr[], int n) {
    int max=-1;
    for(int i=0;i<n;i++)
    max = (max > arr[i])?max:arr[i];
    max++;
    int freq[max];
    for(int i=0;i<max;i++)
    freq[i] = 0;
    for(int i=0;i<n;i++)
    freq[arr[i]]++;
    for(int i=1;i<max;i++)
    freq[i] += freq[i-1];
    int out[n+1];
    for(int i=0;i<n;i++) {
        out[freq[arr[i]]] = arr[i];
        freq[arr[i]]--;
    }
    for(int i=1;i<n+1;i++)
    cout << out[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    count_sort(arr, n);
    return 0;
}
