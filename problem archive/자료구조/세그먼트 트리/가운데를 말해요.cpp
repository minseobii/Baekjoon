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
int K,N,tree[80000];

void update(int start, int end, int idx, int value) {
    if (value < start || end < value) return;
    tree[idx] += 1;
    if (start == end) return;
    
    int mid = (start + end) / 2;
    update(start, mid, idx*2, value);
    update(mid+1, end, idx*2+1, value); 
}

int query(int start, int end, int idx, int value) {
    if (start == end) return start - 10000;

    int mid = (start + end) / 2;
    int left = tree[idx*2];
    if (value <= left) return query(start, mid, idx*2, value);
    else return query(mid+1, end, idx*2+1, value-left);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> K;
        update(0,20000,1,K+10000);
        if (i % 2) cout << query(0,20000,1,i/2+1) << '\n';
        else cout << query(0,20000,1,i/2) << '\n';
    }
    return 0;
}
