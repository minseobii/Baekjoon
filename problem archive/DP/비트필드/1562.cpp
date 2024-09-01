#include <iostream>
#define MOD 1000000000
using namespace std;
int N,ans;
int DP[10][100][1024];

int dp(int num, int idx, int bit) {
    if (DP[num][idx][bit] != -1) return DP[num][idx][bit];
    if (((1 << num) & bit) == 0) {
        return DP[num][idx][bit] = 0;
    }
    if (idx == N-1) {
        if (bit == (1 << num)) {
            return DP[num][idx][bit] = 1;
        }
        else return DP[num][idx][bit] = 0;
    }
    
    if (num == 0) {
        return DP[num][idx][bit] = (dp(num+1,idx+1,(~(1<<num)) & bit) + dp(num+1,idx+1,bit)) % MOD;
    }
    else if (num == 9) {
        return DP[num][idx][bit] = (dp(num-1,idx+1,(~(1<<num)) & bit) + dp(num-1,idx+1,bit)) % MOD;
    }
    else {
        int minus = (dp(num-1,idx+1,(~(1<<num)) & bit) + dp(num-1,idx+1,bit)) % MOD;
        int plus = (dp(num+1,idx+1,(~(1<<num)) & bit) + dp(num+1,idx+1,bit)) % MOD;
        return DP[num][idx][bit] = (minus + plus) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<10;i++) {
        for (int j=0;j<100;j++) {
            for (int k=0;k<1024;k++) {
                DP[i][j][k] = -1;
            }
        }
    }
    
    for (int i=1;i<=9;i++) {
        ans = (ans+dp(i,0,1023)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
