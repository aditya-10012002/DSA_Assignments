#include<iostream>
#include<cmath>
using namespace std;

int digit(int num, int p) {
    return ((num/(int)pow(10, p))%10);
}
void count_sort(int arr[], int n, int p) {
    int max = 10;
    int freq[max];
    for(int i=0;i<max;i++)
    freq[i] = 0;
    for(int i=0;i<n;i++)
    freq[digit(arr[i], p)]++;
    for(int i=1;i<max;i++)
    freq[i] += freq[i-1];
    int out[n+1];
    for(int i=n-1;i>=0;i--) {
        out[freq[digit(arr[i], p)]] = arr[i];
        freq[digit(arr[i], p)]--;
    }
    for(int i=1;i<n+1;i++)
    arr[i-1] = out[i];
}
int main() {
    int n;
    cout << "Enter length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    int max=-1;
    for(int i=0;i<n;i++)
    max = (max > arr[i])?max:arr[i];
    int c=0;
    while(max != 0) {
        c++;
        max /= 10;
    }
    for(int i=0;i<c;i++)
    count_sort(arr, n, i);
    for(int i=0;i<n;i++)
    cout << arr[i] << " ";
    cout << endl;
    return 0;
}
