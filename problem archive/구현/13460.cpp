#include <iostream>
#include <queue>
using namespace std;
int N,M;
int ans = 11;
char arr[10][10];

struct BALL {
    int Rx,Ry,Bx,By,count;
};

struct BALL cal(int k,int rx,int ry,int bx,int by,int count) {
    if (k == 1) {
        if (rx < bx) {
            while(arr[rx][ry] == '.') {
                if (arr[rx-1][ry] == 'O') {
                    rx--;
                    break;
                }
                else if (arr[rx-1][ry] == '.') rx--;
                else break;
            }
            while(arr[bx][by] == '.') {
                if (arr[bx-1][by] == 'O') {
                    bx--;
                    break;
                }
                else if (arr[bx-1][by] == '.' && !(bx-1 == rx && by == ry)) bx--;
                else break;
            }
        }
        else {
            while(arr[bx][by] == '.') {
                if (arr[bx-1][by] == 'O') {
                    bx--;
                    break;
                }
                else if (arr[bx-1][by] == '.') bx--;
                else break;
            }
            while(arr[rx][ry] == '.') {
                if (arr[rx-1][ry] == 'O') {
                    rx--;
                    break;
                }
                else if (arr[rx-1][ry] == '.' && !(rx-1 == bx && ry == by)) rx--;
                else break;
            }
        }
    }

    else if (k == 2) {
        if (rx > bx) {
            while(arr[rx][ry] == '.') {
                if (arr[rx+1][ry] == 'O') {
                    rx++;
                    break;
                }
                else if (arr[rx+1][ry] == '.') rx++;
                else break;
            }
            while(arr[bx][by] == '.') {
                if (arr[bx+1][by] == 'O') {
                    bx++;
                    break;
                }
                else if (arr[bx+1][by] == '.' && !(bx+1 == rx && by == ry)) bx++;
                else break;
            }
        }
        else {
            while(arr[bx][by] == '.') {
                if (arr[bx+1][by] == 'O') {
                    bx++;
                    break;
                }
                else if (arr[bx+1][by] == '.') bx++;
                else break;
            }
            while(arr[rx][ry] == '.') {
                if (arr[rx+1][ry] == 'O') {
                    rx++;
                    break;
                }
                else if (arr[rx+1][ry] == '.' && !(rx+1 == bx && ry == by)) rx++;
                else break;
            }
        }
    }

    else if (k == 3) {
        if (ry < by) {
            while(arr[rx][ry] == '.') {
                if (arr[rx][ry-1] == 'O') {
                    ry--;
                    break;
                }
                else if (arr[rx][ry-1] == '.') ry--;
                else break;
            }
            while(arr[bx][by] == '.') {
                if (arr[bx][by-1] == 'O') {
                    by--;
                    break;
                }
                else if (arr[bx][by-1] == '.' && !(bx == rx && by-1 == ry)) by--;
                else break;
            }
        }
        else {
            while(arr[bx][by] == '.') {
                if (arr[bx][by-1] == 'O') {
                    by--;
                    break;
                }
                else if (arr[bx][by-1] == '.') by--;
                else break;
            }
            while(arr[rx][ry] == '.') {
                if (arr[rx][ry-1] == 'O') {
                    ry--;
                    break;
                }
                else if (arr[rx][ry-1] == '.' && !(rx == bx && ry-1 == by)) ry--;
                else break;
            }
        }
    }

    else if (k == 4) {
        if (ry > by) {
            while(arr[rx][ry] == '.') {
                if (arr[rx][ry+1] == 'O') {
                    ry++;
                    break;
                }
                else if (arr[rx][ry+1] == '.') ry++;
                else break;
            }
            while(arr[bx][by] == '.') {
                if (arr[bx][by+1] == 'O') {
                    by++;
                    break;
                }
                else if (arr[bx][by+1] == '.' && !(bx == rx && by+1 == ry)) by++;
                else break;
            }
        }
        else {
            while(arr[bx][by] == '.') {
                if (arr[bx][by+1] == 'O') {
                    by++;
                    break;
                }
                else if (arr[bx][by+1] == '.') by++;
                else break;
            }
            while(arr[rx][ry] == '.') {
                if (arr[rx][ry+1] == 'O') {
                    ry++;
                    break;
                }
                else if (arr[rx][ry+1] == '.' && !(rx == bx && ry+1 == by)) ry++;
                else break;
            }
        }
    }

    BALL ball = {rx,ry,bx,by,count+1};
    return ball;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int hx,hy,rx,ry,bx,by;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char c;
            cin >> c;
            if (c == '.' || c == '#') arr[i][j] = c;
            else if (c == 'O') {
                hx = i;
                hy = j;
                arr[i][j] = c;
            }
            else {
                if (c == 'R') {
                    rx = i;
                    ry = j;
                }
                else if (c == 'B') {
                    bx = i;
                    by = j;
                }
                arr[i][j] = '.';
            }
        }
    }

    queue<BALL> q;
    BALL ball = {rx,ry,bx,by,0};
    q.push(ball);

    while(!q.empty()) {
        int Rx = q.front().Rx;
        int Ry = q.front().Ry;
        int Bx = q.front().Bx;
        int By = q.front().By;
        int count = q.front().count;

        q.pop();

        if (Rx == hx && Ry == hy) {
            if (Bx == hx && By == hy) continue;
            else {
                ans = min(ans,count);
                continue;
            }
        }
        else if (Bx == hx && By == hy) continue;
        else if (count == 10) continue;

        for (int i=1;i<=4;i++) {
            q.push(cal(i,Rx,Ry,Bx,By,count));
        }
    }

    if (ans == 11) ans = -1;

    cout << ans << endl;
    return 0;
}
