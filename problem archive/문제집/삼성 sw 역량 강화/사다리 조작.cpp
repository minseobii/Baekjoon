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
int N,M,H,arr[31][10];
int ans = 4;

void check(int cnt) {
    for (int k=0;k<N;k++) {
        int r = 0;
        int c = k;
        while(r < H) {
            if (arr[r][c]) {
                r += 1;
                c += 1;
            }
            else if (c>0 && arr[r][c-1]) {
                r += 1;
                c -= 1;
            }
            else {
                r += 1;
            }
        }
        if (k != c) return;
    }
    ans = min(ans, cnt);
}

void dfs(int k, int cnt) {
    check(cnt);
    if (cnt == 3 || k >= H*(N-1)) return;
    for (int i=k;i<H*(N-1);i++) {
        int r = i/(N-1);
        int c = i%(N-1);
        if (arr[r][c] || (c>0 && arr[r][c-1]) || (c<N-2 && arr[r][c+1])) continue;
        arr[r][c] = 1;
        dfs(r*(N-1)+c+1,cnt+1);
        arr[r][c] = 0;
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

    dfs(0,0);

    if (ans == 4) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}
