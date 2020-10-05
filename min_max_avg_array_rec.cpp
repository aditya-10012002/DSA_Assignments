#include<iostream>
#include<cmath>
using namespace std;

void Arr(int a[], int n, int &max1, int &min1, int &sum) {
    if(n == 1) {
        max1 = max(a[0], max1);
        min1 = min(a[0], min1);
        sum += a[0];
    } else {
        Arr(a, n-1, max1=max(a[n-1], max1), min1=min(min1, a[n-1]), sum += a[n-1]);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];
    int max1 = a[0], min1 = a[0], sum = 0;
    Arr(a, n, max1, min1, sum);
    cout << max1 << " " << min1 << " " << sum/n << endl;
    return 0;
}
