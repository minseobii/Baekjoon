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
using namespace std;
int N,M,ans,arr[300][300];
bool visit[300][300];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

void dfs(int r, int c) {
    for (int i=0;i<4;i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr<0 || nc<0 || nr>= N || nc>=M || visit[nr][nc] || arr[nr][nc] == 0) continue;
        visit[nr][nc] = true;
        dfs(nr,nc);
    }
}

bool issplit() {
    bool imposs = true;
    int split = 0;

    memset(visit,0,sizeof(visit));

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (visit[i][j] || arr[i][j] == 0) continue;
            visit[i][j] = true;
            imposs = false;
            split++;
            dfs(i,j); 
        }
    }

    if (imposs == true) {
        ans = 0;
        return true;
    }
    else if (split > 1) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {
        if (issplit()) break;

        int temp[300][300] = {0,}; 
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                if (arr[i][j] == 0) continue;
                for (int k=0;k<4;k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (arr[nr][nc] == 0) temp[i][j]++;
                }
            }
        }

        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                arr[i][j] = max(arr[i][j] - temp[i][j], 0);
            }
        }

        ans++;
    }
    
    cout << ans << '\n';
    return 0;
}
