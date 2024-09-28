#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 2000000001
using namespace std;
int T,N;
int arr[500];
int sum[501];
int DP[500][500];

int dp(int l, int r) {
    if (l == r) return 0;
    if (DP[l][r]) return DP[l][r];

    int &ret = DP[l][r];
    ret = INF;

    int s = sum[r+1] - sum[l];

    for (int k=l;k<r;k++) {
        ret = min(dp(l,k) + dp(k+1,r) + s, ret);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N;
        
        for (int i=0;i<N;i++) {
            cin >> arr[i];
            sum[i+1] = sum[i] + arr[i];
            for (int j=0;j<N;j++) {
                DP[i][j] = 0;
            }
        }

        cout << dp(0,N-1) << '\n';
    }
    return 0;
}
