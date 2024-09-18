#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,K,L,idx;
int t = 1;

struct PAIR {
    int x,y;
};

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool apple[101][101];
bool body[101][101];
vector<pair<int,char>> turn;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i=0;i<K;i++) {
        int a,b;
        cin >> a >> b;
        apple[a][b] = true;
    }
    cin >> L;
    for (int i=0;i<L;i++) {
        int a;
        char b;
        cin >> a >> b;
        turn.push_back({a,b});
    }

    queue<PAIR> q;
    PAIR snake = {1,1};
    q.push(snake);
    int dir = 0;

    while(1) {
        snake.x = snake.x + dx[dir];
        snake.y = snake.y + dy[dir];

        if (snake.x == 0 || snake.x == N+1 || snake.y == 0 || snake.y == N+1 || body[snake.x][snake.y]) {
            break;
        } 

        if (apple[snake.x][snake.y] == false) {
            PAIR cut = q.front();
            body[cut.x][cut.y] = false;
            q.pop();
        }
        else apple[snake.x][snake.y] = false;

        q.push(snake);
        body[snake.x][snake.y] = true;

        if (turn[idx].first == t) {
            if (turn[idx].second == 'L') {
                dir--;
            }
            else dir++;

            if (dir == -1) dir = 3;
            else if (dir == 4) dir = 0;

            idx++;
        }
        t++;
    }

    cout << t << '\n';
    return 0;
}
