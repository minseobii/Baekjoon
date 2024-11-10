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
#define INF 100000001
using namespace std;
int k,N,DP[100000][2];
int ans = -INF;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> k;
        if (i == 0) {
            DP[i][0] = -INF;
            DP[i][1] = k;
        }
        else if (i == 1) {
            DP[i][0] = DP[i-1][1];
            DP[i][1] = max(DP[i-1][1]+k, k); 
        }
        else {
            DP[i][0] = max(DP[i-1][0]+k, DP[i-1][1]);
            DP[i][1] = max(DP[i-1][1]+k,k);
        }

        ans = max(ans, DP[i][0]);
        ans = max(ans, DP[i][1]);
    }
    cout << ans << '\n'; 
    return 0;
}
