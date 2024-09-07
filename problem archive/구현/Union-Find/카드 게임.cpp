#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N,M,K;

unordered_map<int,int> m;
int arr[4000001];
int idx[4000001];
int parent[4000001];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;

    parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;

    for (int i=0;i<M;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+M);
    for (int i=0;i<M;i++) {
        parent[i] = i;
        m[arr[i]] = i+1;
    }

    int p = -1;
    for (int i=N;i>=1;i--) {
        if (m[i]) {
            idx[i] = p;
            p = m[i]-1;
        }
        else {
            idx[i] = p;
        }
    }

    for (int i=0;i<K;i++) {
        int k;
        cin >> k;

        int l = idx[k];
        int card = find(l);
        merge(card,card+1);

        cout << arr[card] << '\n';
    }
    return 0;
}
