#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 100000000000001
using namespace std;
int N,D;
long long ans = -INF;
long long DP[100001];
long long tree[400000];

void update(int start, int end, int idx, int key, long long value) {
    tree[idx] = max(tree[idx], value);
    if (start == end) {
        return;
    }

    int mid = (start + end) / 2;
    if (key <= mid) update(start, mid, idx*2, key, value);
    else update(mid+1, end, idx*2+1, key, value);
}

long long query_max(int start, int end, int left, int right, int idx) {
    if (right < start || end < left) return -INF;
    if (left <= start && end <= right) return tree[idx];

    int mid = (start + end) / 2;
    return max(query_max(start, mid, left, right, idx*2), query_max(mid+1, end, left, right, idx*2+1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> D;
    for (int i=1;i<=N;i++) {
        cin >> DP[i];
    }
    for (int i=0;i<400000;i++) {
        tree[i] = -INF;
    }
 
    for (int i=1;i<=N;i++) {
        DP[i] = max(query_max(1, N, i-D, i-1, 1)+DP[i], DP[i]);
        update(1, N, 1, i, DP[i]);
    }

    for (int i=1;i<=N;i++) {
        ans = max(ans, DP[i]);
    }

    cout << ans << '\n';
    return 0;
}
