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
int N,ans,arr[20][2];

void dfs(int sum, int day) {
    if (day == N) {
        ans = max(ans, sum);
        return;
    }

    if (day + arr[day][0] <= N) dfs(sum+arr[day][1], day+arr[day][0]);
    dfs(sum, day+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    dfs(0,0);

    cout << ans << '\n';
    return 0;
}
