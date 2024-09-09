#include <iostream>
#define MOD 10007
using namespace std;
int N,ans;

int DP[50][50];

int nCr(int n, int r) {
    if(n == r || r == 0) 
        return 1; 
    else if (DP[n][r]) return DP[n][r];
    else {
        DP[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
        return DP[n][r];
    }
}

int cal(int k) {
    return ((nCr(13,k) % MOD) * (nCr(52-(4*k),N-(4*k)) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;4*i<=N;i++) {
        if (i%2==1) ans += cal(i);
        else ans -= cal(i);
    }

    while(ans<0) {
        ans += MOD;
    }

    cout << ans % MOD << endl;
    return 0;
}
