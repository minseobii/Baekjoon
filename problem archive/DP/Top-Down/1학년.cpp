#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int N,arr[100];
long long cache[100][100][21];

long long dp(int S, int E, int sum) {
    if (cache[S][E][sum] != -1) return cache[S][E][sum];
    if (S == E) {
        if (sum == arr[S]) cache[S][E][sum] = 1;
        else cache[S][E][sum] = 0;
        return cache[S][E][sum];
    }

    long long &ret = cache[S][E][sum];
    ret = 0;
    if (sum + arr[E] <= 20) cache[S][E][sum] += dp(S,E-1,sum+arr[E]);
    if (sum - arr[E] >= 0) cache[S][E][sum] += dp(S,E-1,sum-arr[E]);
    return cache[S][E][sum];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    memset(cache, -1, sizeof(cache));

    cout << dp(0,N-2,arr[N-1]) << '\n';
    return 0;
}
