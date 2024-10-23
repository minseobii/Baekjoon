#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000000
using namespace std;
int N,arr[5005],cache[5005];
string s;

int dp(int x) {
    if (cache[x] != -1) return cache[x];
    if (x == 0) return 0;
    if (x == 1) return 1;
    if (x == 2) {
        if (arr[1] == 0) cache[x] = 1;
        else if (arr[0] * 10 + arr[1] > 26) cache[x] = 1;
        else cache[x] = 2;
        return cache[x];
    }

    if (arr[x-1] == 0) cache[x] = dp(x-2);
    else if (arr[x-2] == 0) cache[x] = dp(x-1);
    else if (arr[x-2] * 10 + arr[x-1] > 26) cache[x] = dp(x-1);
    else cache[x] = (dp(x-1) + dp(x-2)) % MOD;
    return cache[x];
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    N = s.length();
    for (int i=0;i<N;i++) {
        arr[i] = s[i] - '0';
    }
    fill(cache,cache+5005,-1);

    if (arr[0] == 0) { // 불가능 케이스
        cout << 0 << '\n';
        return 0;
    }
    for (int i=0;i<N-1;i++) {
        if (arr[i] != 1 && arr[i] != 2 && arr[i+1] == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    
    cout << dp(N) << '\n';

    return 0;
}
