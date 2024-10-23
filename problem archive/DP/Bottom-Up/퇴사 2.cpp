#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans,DP[1500005];
pair<int,int> arr[1500005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i=1;i<=N+1;i++) {
        DP[i] = max(DP[i], DP[i-1]);
        if (i + arr[i].first <= N+1) DP[i+arr[i].first] = max(DP[i+arr[i].first], DP[i]+arr[i].second);
        ans = max(ans, DP[i]);
    }

    cout << ans << '\n';
    return 0;
}
