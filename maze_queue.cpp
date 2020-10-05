#include<iostream>
using namespace std;

struct queue {
    int size;
    int front;
    int rear;
    int elements[50];
};
void enqueue(queue &Q, int x) {
    if((Q.rear+1)%Q.size == Q.front)
    cout << "queue is full\n";
    else {
        if(Q.front == -1) {
            Q.front = 0;
            Q.rear = 0;
        } else {
            Q.rear = (Q.rear+1)%Q.size;
        }
        Q.elements[Q.rear] = x;
    }
}
int dequeue(queue &Q) {
    int t = -1;
    if(Q.front == -1)
    cout << "queue is empty\n";
    else {
        if(Q.front == Q.rear) {
            t = Q.elements[Q.front];
            Q.front = -1;
            Q.rear = -1;
        }
        else {
            t = Q.elements[Q.front];
            Q.front = (Q.front+1)%Q.size;
        }
    }
    return t;
}
void solve(struct queue &x, struct queue &y, int maze[][8], int sx, int sy, int dx, int dy) {
    if(maze[sx][sy] == 0) {
        cout << "0\n";
        return;
    }
    enqueue(x, sx);
    enqueue(y, sy);
    maze[sx][sy] = 0;
    while (true) {
        if(x.rear == -1) {
            cout << "0\n";
            break;
        }
        int tx = dequeue(x);
        int ty = dequeue(y);
        if(tx == dx && ty == dy) {
            cout << "1\n";
            break;
        }
        if(ty-1 >=0 && maze[tx][ty-1] == 1) {
            maze[tx][ty-1] = 0;
            enqueue(x, tx);
            enqueue(y, ty-1);
        } if(ty+1 < 8 && maze[tx][ty+1] == 1) {
            maze[tx][ty+1] = 0;
            enqueue(x, tx);
            enqueue(y, ty+1);
        } if(tx-1 >=0 && maze[tx-1][ty] == 1) {
            maze[tx-1][ty] = 0;
            enqueue(x, tx-1);
            enqueue(y, ty);
        } if(tx+1 < 8 && maze[tx+1][ty] == 1) {
            maze[tx+1][ty] = 0;
            enqueue(x, tx+1);
            enqueue(y, ty);
        }
    }
}
int main() {
    struct queue S1;
    S1.size = 50;
    S1.front = -1;
    S1.rear = -1;
    struct queue S2;
    S2.size = 50;
    S2.front = -1;
    S2.rear = -1;

    int maze[8][8];
    int n = 8;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    maze[i][j] = 0;
    int sx, sy, dx, dy;
    cout << "enter coordinates\n";
    cin >> sx >> sy >> dx >> dy;
    for(int i=1;i<=6;i++)
    maze[1][i] = 1;
    maze[2][1] = 1;
    maze[2][3] = 1;
    maze[3][3] = 1;
    maze[3][4] = 1;
    maze[3][5] = 1;
    maze[3][6] = 1;
    maze[4][6] = 1;
    maze[5][6] = 1;
    maze[6][6] = 1;
    maze[3][1] = 1;
    maze[5][1] = 1;
    maze[6][1] = 1;
    maze[6][2] = 1;
    maze[6][3] = 1;
    maze[6][4] = 1;
    maze[5][4] = 1;

    if(sx < 0 || sx > 7 || sy < 0 || sy > 7 || dx < 0 || dx > 7 || dy < 0 || dy > 7) {
        cout << "0\n";
        return 0;
    }

    solve(S1, S2, maze, sx, sy, dx, dy);

    return 0;
}
