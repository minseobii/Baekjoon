#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 100000
using namespace std;
int N,arr[21][21];
int ans = MAX;
bool visit[21][21];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int BFS(int r1, int r2, int c1, int c2, int num, bool type, int start1, int start2) {
    queue<pair<int,int>> q;
    int temp_ans = 0;
    if (r1 <= start1 && start1 <= r2 && c1 <= start2 && start2 <= c2) {
        visit[start1][start2] = true;
        temp_ans += arr[start1][start2];
        q.push({start1,start2});
    }

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k=0;k<4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx<r1 || nx>r2 || ny<c1 || ny>c2 || (type && (nx+ny == num)) || (!type && (N-nx+ny == num)) || visit[nx][ny]) continue;
            visit[nx][ny] = true;
            temp_ans += arr[nx][ny];
            q.push({nx,ny});
        }
    }

    return temp_ans;
}

void solve(int i, int j, int d1, int d2) {
    vector<int> v;
    v.push_back(BFS(1,i+d1-1,1,j,i+j,true,1,1));
    v.push_back(BFS(1,i+d2,j+1,N,N-i+j,false,1,N));
    v.push_back(BFS(i+d1,N,1,j-d1+d2-1,N-(i+d1)+j-d1,false,N,1));
    v.push_back(BFS(i+d2+1,N,j-d1+d2,N,i+d2+j+d2,true,N,N));

    int temp_ans = 0;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (visit[i][j] == false) temp_ans += arr[i][j];
        }
    }
    v.push_back(temp_ans);

    sort(v.begin(),v.end());
    ans = min(ans, v[4]-v[0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            for (int d1=1;d1<N;d1++) {
                for (int d2=1;d2<N;d2++) {
                    if (i+d1+d2>N || j-d1<0 || j+d2>N) continue;
                    memset(visit,false,sizeof(visit));
                    solve(i,j,d1,d2);
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
