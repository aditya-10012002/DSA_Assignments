#include<iostream>
using namespace std;

void window(int arr[], int low, int high) {
    if(low >= high) {
        cout << "Sorted\n";
    } else if(arr[low] > arr[low+1] && arr[high] < arr[high-1]) {
        cout << "Sort the array from index " << low << " to " << high << endl;
    } else if(arr[low] <= arr[low+1] && arr[high] >= arr[high-1]) {
        window(arr, low+1, high-1);
    } else if(arr[low] <= arr[low+1]) {
        window(arr, low+1, high);
    } else if(arr[high] >= arr[high-1]) {
        window(arr, low, high-1);
    }
}
int main() {
    cout << "Enter array length\n";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter array elements\n";
    for(int i=0;i<n;i++)
    cin >> arr[i];
    window(arr, 0, n-1);
    return 0;
}
