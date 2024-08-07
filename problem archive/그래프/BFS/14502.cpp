#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,M,zero;
int arr[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans;

void solve(int a, int b, int c) {
    int tempzero=0;
    int visit[8][8] = {0,};
    if (arr[a/M][a%M] || arr[b/M][b%M] || arr[c/M][c%M]) {
        return;
    }
    arr[a/M][a%M] = 1;
    arr[b/M][b%M] = 1;
    arr[c/M][c%M] = 1;

    queue<pair<int, int>> q;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 2){ 
                q.push({i,j});
                visit[i][j] = 1;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int k=0;k<4;k++) {
                        
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[nx][ny] == 1 || arr[nx][ny]) {
                continue;
            }
            tempzero++;
            q.push({nx,ny});
            visit[nx][ny] = 1;
        }
    }
    ans = max(zero-tempzero-3, ans);
    arr[a/M][a%M] = 0;
    arr[b/M][b%M] = 0;
    arr[c/M][c%M] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                zero++;
            }
        }
    }

    int subarr[N*M];
    for (int i=0;i<N*M;i++) {
        if (i < 3) {
            subarr[i] = 1;
        }
        else {
            subarr[i] = 0;
        }
    }

    do { 
        int a[3];
        int idx=0;
        for (int i=0;i<N*M;i++) {
            if (subarr[i]) {
                a[idx++] = i;
            }
        }
        solve(a[0],a[1],a[2]);
    } while(prev_permutation(subarr,subarr+N*M));

    cout << ans << endl;
    return 0;
}
