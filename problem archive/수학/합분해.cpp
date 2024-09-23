#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000000000
using namespace std;
int N,K,ans;
int DP[400][200];

int nCr(int n, int r) {
    if (n == r || r == 0) return 1;
    if (DP[n][r]) return DP[n][r];

    DP[n][r] = (nCr(n-1,r-1) + nCr(n-1,r)) % MOD;
    return DP[n][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    cout << nCr(N+K-1,K-1) << '\n';
    return 0;
}
