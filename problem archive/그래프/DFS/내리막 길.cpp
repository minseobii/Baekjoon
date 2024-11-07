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
int M,N,ans,arr[500][500],cache[500][500];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int dp(int r, int c) {
    if (cache[r][c] != -1) return cache[r][c];
    if (r == 0 && c == 0) return 1;

    cache[r][c] = 0;
    for (int k=0;k<4;k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr<0 || nc<0 || nr>=M || nc>=N || arr[r][c]>=arr[nr][nc]) continue;

        cache[r][c] += dp(nr, nc);
    }

    return cache[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;

    for (int i=0;i<M;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    memset(cache,-1,sizeof(cache));

    cout << dp(M-1,N-1) << '\n';
    return 0;
}
