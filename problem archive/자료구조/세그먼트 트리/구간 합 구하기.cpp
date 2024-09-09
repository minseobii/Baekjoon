#include <iostream>
using namespace std;
int N,M,K;
long long arr[1000001];
long long segtree[4000005];

long long init(int start, int end, int idx) {
    if (start == end) {
        segtree[idx] = arr[start];
        return segtree[idx];
    }

    int mid = (start + end) / 2;
    segtree[idx] = init(start, mid, idx * 2) + init(mid+1, end, idx * 2 + 1);
    return segtree[idx];
}

void replace(int start, int end, int key, long long value, int idx) {
    if (start > key || end < key) return;
    segtree[idx] += value;

    if (start == end) return;

    int mid = (start + end) / 2;
    replace(start,mid,key,value,idx*2);
    replace(mid+1,end,key,value,idx*2+1);
}

long long sum(int start, int end, int left, int right, int idx) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return segtree[idx];

    int mid = (start + end) / 2;
    return sum(start,mid,left,right,idx*2) + sum(mid+1,end,left,right,idx*2+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    init(1,N,1);


    for (int i=0;i<M+K;i++) {
        int a,b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) {
            replace(1,N,b,c-arr[b],1);
            arr[b] = c;
        }
        else if (a == 2) {
            cout << sum(1,N,b,c,1) << '\n';
        }
    }
    return 0;
}
