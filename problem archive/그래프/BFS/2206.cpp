#include <iostream>
#include <queue>
using namespace std;
int N,M;
int arr[1001][1001];
int ans = -1;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

struct PAIR {
    int i,j,depth;
    bool b;
};

void BFS(int i,int j){
    int visit[1001][1001][2] = {0,};
    queue<PAIR> q;          
    PAIR pair = {i,j,1,false};
    q.push(pair);

    visit[i][j][0] = 1;

    while (!q.empty()) {

        int x = q.front().i;
        int y = q.front().j;
        int depth = q.front().depth;
        bool b = q.front().b;
        q.pop();

        if (x==N && y==M) {
            if (ans == -1) {
                ans = depth;
            }
            else {
                ans = min(ans, depth);
            }
            continue;
        }

        for (int k=0;k<4;k++) {
            int nx = x + dy[k];
            int ny = y + dx[k];

            if (nx <= 0 || ny <= 0 || nx > N || ny > M) {
                continue;
            }
            if (arr[nx][ny] == 0) {
                if (visit[nx][ny][0] == 0 && b == false) {
                    PAIR newpair = {nx,ny,depth+1,b};
                    q.push(newpair);
                    visit[nx][ny][0] = 1;
                }
                else if (visit[nx][ny][1] == 0 && b == true) {
                    PAIR newpair = {nx,ny,depth+1,b};
                    q.push(newpair);
                    visit[nx][ny][1] = 1;
                }
            }
            if (arr[nx][ny] && b == false) {
                PAIR newpair = {nx,ny,depth+1,true};
                q.push(newpair);
                visit[nx][ny][1] = 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            char a;
            cin >> a;
            if (a == '0') {
                arr[i][j] = 0;
            }
            else {
                arr[i][j] = 1;
            }
        }
    }
    BFS(1,1);
    
    cout << ans << endl;
    return 0;
}
