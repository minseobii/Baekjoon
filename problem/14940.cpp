#include <iostream>
#include <queue>
using namespace std;
int N,M;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

struct PAIR{
    int i,j,depth;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    int arr[N][M];
    int visited[N][M];
    int ansarr[N][M];

    int target1 = 0;
    int target2 = 0;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 2) {
                target1 = i;
                target2 = j;
            }
            visited[i][j] = 0;
            ansarr[i][j] = 0;
        }
    }

    queue<PAIR> q;          
    PAIR pair = {target1,target2,0};
    q.push(pair);

    ansarr[target1][target2] = 0;
    visited[target1][target2] = 1;

    while (!q.empty()) {
        int y = q.front().i;
        int x = q.front().j;
        int depth = q.front().depth;
        q.pop();

        for (int k=0;k<4;k++) {
                        
            int ny = y + dy[k];
            int nx = x + dx[k];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] == 1 || arr[ny][nx] != 1) {
                continue;
            }
            PAIR newpair = {ny,nx,depth+1};
            ansarr[ny][nx] = depth+1;
            visited[ny][nx] = 1;
            q.push(newpair);
        }
    }


    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 1 && ansarr[i][j] == 0) {
                ansarr[i][j] = -1;
            }
            cout << ansarr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
