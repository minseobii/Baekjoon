#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000000007
using namespace std;
int M,N,K;
long long factorial[4000001];

void init() {
    factorial[0] = 1;
    for (long long i=1;i<=4000000;i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

long long reverse_mod(long long a) {
    long long ret = 1;
    long long x = MOD-2;
    while(x > 0) {
        if (x%2) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        x /= 2;
    }
    return ret % MOD;
}

long long nCk(int n, int k) {
    return (factorial[n] * reverse_mod((factorial[n-k] * factorial[k]) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;
    init();
    while(M--) {
        cin >> N >> K;
        cout << nCk(N,K) << '\n';
    }
    return 0;
}
