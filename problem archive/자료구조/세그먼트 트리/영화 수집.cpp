#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 100001
using namespace std;
int T,N,M,tree[8*(MAX)],loca[MAX];

int init(int start, int end, int idx) {
    if (start == end) {
        if (start <= N) {
            tree[idx] = 1;
            loca[start] = N - start + 1;
        }
        return tree[idx];
    }

    int mid = (start + end) / 2;
    tree[idx] = init(start, mid, idx*2) + init(mid+1, end, idx*2+1);
    return tree[idx];
}

void update(int start, int end, int key, int value, int idx) {
    if (key < start || end < key) return;
    tree[idx] += value;

    if (start == end) return;

    int mid = (start + end) / 2;
    update(start, mid, key, value, idx*2);
    update(mid+1, end, key, value, idx*2+1);
}

int query(int start, int end, int left, int right, int idx) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[idx];

    int mid = (start + end) / 2;
    return query(start, mid, left, right, idx*2) + query(mid+1, end, left, right, idx*2+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> M;
        fill(tree,tree+(8*MAX),0);
        fill(loca,loca+MAX,0);
        init(1,N+M,1);
        for (int i=1;i<=M;i++) {
            int k;
            cin >> k;
            int cur = loca[k];
            int next = N+i;
            cout << query(1,N+M,cur+1,next,1) << ' ';
            update(1,N+M,cur,-1,1);
            update(1,N+M,next,1,1);
            loca[k] = next;
        }   
        cout << '\n';
    }
    return 0;
}
