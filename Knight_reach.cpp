#include<iostream>
using namespace std;

void reach(int n, int sx, int sy, int dx, int dy, int &min, int c) {
    if(sx == dx && sy == dy) {
        min = (min > c)?c:min;
    } else {
        if(sx-2>=0 && sy+1<n)
        reach(n, sx-2, sy+1, dx, dy, min, c+1);
        if(sx+2<n && sy+1<n)
        reach(n, sx+2, sy+1, dx, dy, min, c+1);
        if(sx-1>=0 && sy+2<n)
        reach(n, sx-1, sy+2, dx, dy, min, c+1);
        if(sx+1<n && sy+2<n)
        reach(n, sx+1, sy+2, dx, dy, min, c+1);
    }
}
int main() {
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy
    int min = 100;
    reach(8, sx, sy, dx, dy, min, 0);
    cout << min << endl;
}
