#include<iostream>
using namespace std;

void convert(int arr1[][5], int i, int j) {
    if(i-1 >= 0 && arr1[i-1][j] < 0) {
        arr1[i-1][j] *= -1;
    }
    if(j-1 >= 0 && arr1[i][j-1] < 0) {
        arr1[i][j-1] *= -1;
    }
    if(i+1 < 4 && arr1[i+1][j] < 0) {
        arr1[i+1][j] *= -1;
    }
    if(j+1 < 5 && arr1[i][j+1] < 0) {
        arr1[i][j+1] *= -1;
    }
}
void equal(int arr[][5], int arr1[][5]) {
    for(int i=0;i<4;i++)
    for(int j=0;j<5;j++)
    arr[i][j] = arr1[i][j];
}
bool isEqual(int arr[][5], int arr1[][5]) {
    for(int i=0;i<4;i++)
    for(int j=0;j<5;j++)
    if(arr1[i][j] != arr[i][j])
    return false;
    return true;
}
int main() {
    int arr1[4][5] =
    {
        {-1, -9, 0, -1, 0},
        {-8, -3, -2, 9, -7},
        {2, 0, 0, -6, 0},
        {0, -7, -3, 5, -4}
    };
    int arr[4][5];
    //equal(arr, arr1);
    int c=0;
    while(!isEqual(arr, arr1)) {
        equal(arr, arr1);
        c++;
        for(int i=0;i<4;i++) {
            for(int j=0;j<5;j++) {
                if(arr[i][j] > 0)
                convert(arr1, i, j);
            }
        }
    }
    cout << c-1 << endl;
    return 0;
}
