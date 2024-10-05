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
int N,M,r,c,d,cnt,arr[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    cin >> r >> c >> d;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }

    while(1) {
        if (arr[r][c] == 0) { // 1
            arr[r][c] = 2;
            cnt++;
        }

        bool find = false;
        for (int i=0;i<4;i++) { // 3-1
            d = (d + 3) % 4;
            int nr = r+dr[d];
            int nc = c+dc[d];
            if (nr<0 || nc<0 || nr>=N || nc>= M || arr[nr][nc] != 0) continue;
            r = nr;
            c = nc;
            find = true;
            break;
        }

        if (!find) { // 2-1
            int nd = (d + 2) % 4;
            r = r + dr[nd];
            c = c + dc[nd];
            if (r<0 || c<0 || r>=N || c>= M || arr[r][c] == 1) break;
        }
    }

    cout << cnt << '\n';
    return 0;
}
