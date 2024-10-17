#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,L,R,A[50][50],ans;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
bool visit[50][50];
vector<pair<int,int>> v;

void dfs(int r, int c) {
    visit[r][c] = true;
    v.push_back({r,c});
    for (int i=0;i<4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr<0 || nc<0 || nr>=N || nc>=N || visit[nr][nc]) continue;

        int dif = abs(A[nr][nc] - A[r][c]);
        if (dif >= L && dif <= R) dfs(nr, nc);
    }
}

bool ismove() {
    bool find = false;
    for (int i=0;i<50;i++) {
        for (int j=0;j<50;j++) {
            visit[i][j] = false;
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (visit[i][j]) continue;
            v.clear();
            dfs(i,j); 
            if (v.size() > 1) {
                find = true;
                int sum = 0;
                for (pair<int,int> k : v) {
                    sum += A[k.first][k.second]; 
                }

                int aver = sum / v.size();
                for (pair<int,int> k : v) {
                    A[k.first][k.second] = aver;
                }
            }
        }
    }

    return find;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L >> R; 
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> A[i][j];
        }
    }

    while(ismove()) ans++;
    cout << ans << '\n';
    return 0;
}
