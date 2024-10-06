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
int N,W,DP[1001][1001];
pair<int,int> A[1001];

int cal_dis(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int dfs(int p1, int p2) {
    int next = max(p1,p2)+1;
    if (next == W+1) return 0;
    if (DP[p1][p2] != -1) return DP[p1][p2];

    int dis1,dis2;
    if (p1 == 0) dis1 = cal_dis(1,1,A[next].first,A[next].second);
    else dis1 = cal_dis(A[p1].first,A[p1].second,A[next].first,A[next].second);
    if (p2 == 0) dis2 = cal_dis(N,N,A[next].first,A[next].second);
    else dis2 = cal_dis(A[p2].first,A[p2].second,A[next].first,A[next].second);

    int ret1 = dis1 + dfs(next, p2);
    int ret2 = dis2 + dfs(p1, next);
    DP[p1][p2] = min(ret1, ret2);

    return DP[p1][p2];
}

void trace(int p1, int p2) {
    int next = max(p1,p2)+1;
    if (next == W+1) return;

    int dis1,dis2;
    if (p1 == 0) dis1 = cal_dis(1,1,A[next].first,A[next].second);
    else dis1 = cal_dis(A[p1].first,A[p1].second,A[next].first,A[next].second);
    if (p2 == 0) dis2 = cal_dis(N,N,A[next].first,A[next].second);
    else dis2 = cal_dis(A[p2].first,A[p2].second,A[next].first,A[next].second);

    int ret1 = dis1 + DP[next][p2];
    int ret2 = dis2 + DP[p1][next];
    if (ret1 < ret2) {
        cout << 1 << '\n';
        trace(next, p2);
    }
    else {
        cout << 2 << '\n';
        trace(p1, next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> W;
    memset(DP,-1,sizeof(DP));
    for (int i=1;i<=W;i++) {
        cin >> A[i].first >> A[i].second;
    }

    cout << dfs(0,0) << '\n';
    trace(0,0);

    return 0;
}
