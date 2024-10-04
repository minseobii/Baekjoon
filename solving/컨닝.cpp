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
int C,N,M;
int arr[10];
int DP[10][1 << 10];
int numcount[1 << 10];

int dp(int r, int bit) {
    if (r == N) return 0;
    if (DP[r][bit] != -1) return DP[r][bit];

    int &ret = DP[r][bit];
    ret = 0;

    for (int i=0;i<(1 << M);i++) {
        if (i&arr[r]) continue;
        bool find = true;
        for (int k=0;k<M;k++) {
            if (i & (1 << k)) {
                if ((k>0 && (i&(1<<k-1))) || (k<M-1&&(i&(1<<k+1)))) find = false;
                if ((k>0 && (bit&(1<<k-1))) || (k<M-1 && (bit&(1<<k+1)))) find = false;
            }
        }

        if (find) ret = max(ret, dp(r+1, i) + numcount[i]);
    }
    return ret;
}

void init() {
    for (int i=0;i<(1 << 10);i++) {
        int n = 0;
        for (int k=0;k<10;k++) {
            if (i&(1<<k)) n++;
        }
        numcount[i] = n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C;
    init();

    while(C--) {
        cin >> N >> M;
        for (int i=0;i<10;i++) {
            arr[i] = 0;
            for (int j=0;j<(1 << 10);j++) {
                DP[i][j] = -1;
            }
        }

        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                char c;
                cin >> c;
                if (c == 'x') arr[i] |= (1 << j);
            }
        }

        cout << dp(0,0) << '\n';
    }
    return 0;
}
