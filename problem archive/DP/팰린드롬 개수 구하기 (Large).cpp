#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 10007
using namespace std;
string s;
int N,ans;
int DP[1000][1000];

int dp(int start, int end) {
    if (start == end) return 1;
    if (start + 1 == end) {
        if (s[start] == s[end]) return 3;
        else return 2;
    }
    if (DP[start][end]) return DP[start][end];

    if (s[start] == s[end]) DP[start][end] = ((dp(start+1,end) + dp(start,end-1)) % MOD + 1) % MOD;
    else DP[start][end] = (dp(start+1,end) + dp(start,end-1) - dp(start+1, end-1)) % MOD;

    if (DP[start][end] < 0) DP[start][end] += MOD;
    return DP[start][end];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    N = s.length();

    cout << dp(0,N-1) << '\n';
    return 0;
}
