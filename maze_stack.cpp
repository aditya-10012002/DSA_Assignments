#include<iostream>
using namespace std;

struct stack {
    int size;
    int top;
    int elements[50];
};
void push(struct stack &S, int x) {
    if(S.top == S.size-1)
    cout << "Stack is full\n";
    else
    S.elements[++S.top] = x;
}
int pop(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top--];
}
int peek(struct stack &S) {
    return (S.top == -1)?-1:S.elements[S.top];
}
bool isEmpty(struct stack &S) {
    return (S.top == -1)?true:false;
}
void solve(struct stack &x, struct stack &y, int maze[][8], int sx, int sy, int dx, int dy) {
    if(maze[sx][sy] == 0) {
        cout << "0\n";
        return;
    }
    push(x, sx);
    push(y, sy);
    maze[sx][sy] = 0;
    while (true) {
        if(isEmpty(x)) {
            cout << "0\n";
            break;
        }
        int tx = pop(x);
        int ty = pop(y);
        if(tx == dx && ty == dy) {
            cout << "1\n";
            break;
        }
        if(ty-1 >=0 && maze[tx][ty-1] == 1) {
            maze[tx][ty-1] = 0;
            push(x, tx);
            push(y, ty-1);
        } if(ty+1 < 8 && maze[tx][ty+1] == 1) {
            maze[tx][ty+1] = 0;
            push(x, tx);
            push(y, ty+1);
        } if(tx-1 >=0 && maze[tx-1][ty] == 1) {
            maze[tx-1][ty] = 0;
            push(x, tx-1);
            push(y, ty);
        } if(tx+1 < 8 && maze[tx+1][ty] == 1) {
            maze[tx+1][ty] = 0;
            push(x, tx+1);
            push(y, ty);
        }
    }
}
int main() {
    struct stack S1;
    S1.size = 50;
    S1.top = -1;
    struct stack S2;
    S2.size = 50;
    S2.top = -1;

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
