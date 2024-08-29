#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int parent[1000001];
int ran[1000001];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (v == u) return;
    
    if (ran[u] > ran[v]) swap(u,v);
    else if (ran[u] == ran[v]) ran[v]++;
    parent[u] = v;
}

bool issameset(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<=N;i++) {
        parent[i] = i;
    }

    for (int i=0;i<M;i++) {
        int comm;
        int a,b;
        cin >> comm >> a >> b;
        if (comm == 0) {
            merge(a,b);
        }
        else if (comm == 1) {
            if (issameset(a,b)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
