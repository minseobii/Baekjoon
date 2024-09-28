#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;
int N;
long long ans;
int A[500001];
int B[1000001];
int tree[2000000];

int segtree_query(int start, int end, int left, int right, int idx) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[idx];

    int mid = (start + end) / 2;
    return segtree_query(start, mid, left, right, idx*2) + segtree_query(mid+1, end, left, right, idx*2+1);
}

void segtree_update(int start, int end, int key, int idx) {
    if (key < start || end < key) return;
    if (start == end) {
        tree[idx] = 1;
        return;
    }

    int mid = (start + end) / 2;
    segtree_update(start, mid, key, idx*2);
    segtree_update(mid+1, end, key, idx*2+1);
    tree[idx] = tree[idx*2] + tree[idx*2+1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
    }
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;
        B[k] = i;
    }

    for (int i=0;i<N;i++) {
        ans += segtree_query(0, N-1, B[A[i]]+1, N-1, 1);
        segtree_update(0, N-1, B[A[i]], 1);
    }

    cout << ans << '\n';
    return 0;
}
