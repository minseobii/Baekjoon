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
int N,M,parent[MAX],value[MAX];

int find(int u) {
    if (u == parent[u]) return u;
    int U = find(parent[u]);
    value[u] += value[parent[u]]; 
    return parent[u] = U;
}

void merge(int u, int v, int w) {
    int U = find(u);
    int V = find(v);
    if (U == V) return;

    value[V] = value[u] - value[v] + w;
    parent[V] = U;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (int i=1;i<=N;i++) {
            parent[i] = i;
            value[i] = 0;
        }

        for (int i=0;i<M;i++) {
            char c;
            int a,b,w;
            cin >> c;
            if (c == '!') {
                cin >> a >> b >> w;
                merge(a,b,w);
            }
            else {
                cin >> a >> b;
                int A = find(a);
                int B = find(b);
                if (A == B) cout << value[b] - value[a] << '\n';
                else cout << "UNKNOWN" << '\n';
            }
        }
    }
    return 0;
}
