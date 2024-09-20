#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,K;
int arr[101];
int DP[10001][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    for (int i=1;i<=K;i++) {
        for (int j=0;j<=N;j++) {
            if (j == 0) {
                DP[i][j] = 10001;
                continue;
            }

            if (arr[j] <= i) {
                DP[i][j] = min(DP[i-arr[j]][N]+1,DP[i][j-1]);
            }
            else DP[i][j] = DP[i][j-1];
        }
    }

    if (DP[K][N] == 10001) cout << -1 << '\n';
    else cout << DP[K][N] << '\n';
    return 0;
}
