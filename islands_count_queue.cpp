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
    int t;
    if(Q.front == -1)
    t = -1;
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
void solve(int mat[][10], int sx, int sy) {
    struct queue x;
    x.size = 50;
    x.front = -1;
    x.rear = -1;
    struct queue y;
    y.size = 50;
    y.front = -1;
    y.rear = -1;
    enqueue(x, sx);
    enqueue(y, sy);
    mat[sx][sy] = 0;
    while (true) {
        int tx = dequeue(x);
        int ty = dequeue(y);
        if(tx == -1 || ty == -1) {
            break;
        }
        if(ty-1 >=0 && mat[tx][ty-1] == 1) {
            mat[tx][ty-1] = 0;
            enqueue(x, tx);
            enqueue(y, ty-1);
        } if(ty+1 < 10 && mat[tx][ty+1] == 1) {
            mat[tx][ty+1] = 0;
            enqueue(x, tx);
            enqueue(y, ty+1);
        } if(tx-1 >=0 && mat[tx-1][ty] == 1) {
            mat[tx-1][ty] = 0;
            enqueue(x, tx-1);
            enqueue(y, ty);
        } if(tx+1 < 10 && mat[tx+1][ty] == 1) {
            mat[tx+1][ty] = 0;
            enqueue(x, tx+1);
            enqueue(y, ty);
        }

        if(tx-1 >= 0 && ty-1 >= 0) {
            if(mat[tx-1][ty-1] == 1) {
                mat[tx-1][ty-1] = 0;
                enqueue(x, tx-1);
                enqueue(y, ty-1);
            }
        } if(ty+1 < 10 && tx+1 < 10) {
            if(mat[tx+1][ty+1] == 1) {
                mat[tx+1][ty+1] = 0;
                enqueue(x, tx+1);
                enqueue(y, ty+1);
            }
        } if(ty+1 < 10 && tx-1 >= 0) {
            if(mat[tx-1][ty+1] == 1) {
                mat[tx-1][ty+1] = 0;
                enqueue(x, tx-1);
                enqueue(y, ty+1);
            }
        } if(tx+1 < 10 && ty-1 < 10) {
            if(mat[tx+1][ty-1] == 1) {
                mat[tx+1][ty-1] = 0;
                enqueue(x, tx+1);
                enqueue(y, ty-1);
            }
        }
    }
}
int main() {
    int mat[10][10] =
    {
        {1, 0, 1, 0, 0, 0, 1, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
        {0, 1, 0, 1, 0, 0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {1, 1, 1, 1, 0, 0, 0, 1, 1, 1}
    };
    int c=0;
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++) {
        if(mat[i][j] == 1) {
            c++;
            solve(mat, i, j);
        }
    }
    cout << c << endl;
    return 0;
}
