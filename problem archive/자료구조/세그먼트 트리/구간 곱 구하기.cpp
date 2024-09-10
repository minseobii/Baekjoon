#include <iostream>
#define MOD 1000000007
using namespace std;

int N,M,K;
long long arr[1000001];
long long segtree[4000005];

long long mod_inverse(long long a) {
    long long n = MOD-2;
    long long ans = 1;
    while(n > 0) {
        if (n%2) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return ans;
}

long long init(int start, int end, int idx) {
    if (start == end) {
        segtree[idx] = arr[start];
        return segtree[idx];
    }

    int mid = (start + end) / 2;
    segtree[idx] = (init(start, mid, idx * 2) * init(mid+1, end, idx * 2 + 1)) % MOD;
    return segtree[idx];
}

void update(int start, int end, int key, long long oldvalue, long long newvalue,int idx) {
    if (start > key || end < key) return;

    if (oldvalue == 0) {
        if (start == end) {
            segtree[idx] = newvalue;
            return;
        }
    }
    else if (newvalue == 0) {
        if (start == end) {
            segtree[idx] = 0;
            return;
        }
    }
    else {
        segtree[idx] = (((segtree[idx] * mod_inverse(oldvalue)) % MOD) * newvalue) % MOD;
        if (start == end) return;
    }

    int mid = (start + end) / 2;
    update(start,mid,key,oldvalue,newvalue,idx*2);
    update(mid+1,end,key,oldvalue,newvalue,idx*2+1);
}

long long multiple(int start, int end, int left, int right, int idx) {
    if (left > end || right < start) return 1;
    if (left <= start && end <= right) return segtree[idx];

    int mid = (start + end) / 2;
    return (multiple(start,mid,left,right,idx*2) * multiple(mid+1,end,left,right,idx*2+1)) % MOD;
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
            update(1,N,b,arr[b],c,1);
            arr[b] = c;
        }
        else if (a == 2) {
            cout << multiple(1,N,b,c,1) << '\n';
        }
        // for (int i=1;i<10;i++) {
        //   cout << segtree[i] << ' ';
        // }
        // cout << endl;
    }
    return 0;
}
