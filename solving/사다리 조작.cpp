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
int N,M,H,arr[30][9];
int ans = 4;

void check(int cnt) {
    for (int k=0;k<N;k++) {
        int r = 0;
        int c = k;
        while(r < H) {
            if (c>0 && arr[r][c-1]) {
                r += 1;
                c -= 1;
            }
            else if (c<N-2 && arr[r][c+1]) {
                r += 1;
                c += 1;
            }
            else {
                r += 1;
            }
        }
        if (k != c) return;
    }
    ans = min(ans, cnt);
}

void dfs(int r, int c, int cnt) {
    check(cnt);
    if (cnt == 3 || r >= H || c >= N-1) return;

    for (int j=c;j<N-1;j++) {
        if ((j>0 && arr[r][j-1]) || (j<N-2 && arr[r][j+1])) continue;
        if (!arr[r][j]) {
            arr[r][j] = 1;
            if (j+1 == N-1) {
                dfs(r+1,0,cnt+1);
            }
            else {
                dfs(r,c+1,cnt+1);
            }
            arr[r][j] = 0;
        }
    }
    r += 1;
    for (int i=r;i<H;i++) {
        for (int j=0;j<N-1;j++) {
            if ((j>0 && arr[r][j-1]) || (j<N-2 && arr[r][j+1])) continue;
            if (!arr[r][j]) {
                arr[r][j] = 1;
                if (j+1 == N-1) {
                    dfs(r+1,0,cnt+1);
                }
                else {
                    dfs(r,c+1,cnt+1);
                }
                arr[r][j] = 0;
            } 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> H;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        arr[a-1][b-1] = 1;
    }

    dfs(0,0,0);

    if (ans == 4) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}
