#include <iostream>
#include <algorithm>
using namespace std;
int N,M,ans;
int parent[500000];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        parent[i] = i;
    }
    for (int i=1;i<=M;i++) {
        int a,b;
        cin >> a >> b;
        
        if (find(a) == find(b)) {
            ans = i;
            break;
        }
        merge(a,b);
    }
    cout << ans << endl;
    return 0;
}
