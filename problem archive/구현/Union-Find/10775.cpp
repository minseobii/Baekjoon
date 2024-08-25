#include <iostream>
using namespace std;
int G,P,ans;
int parent[100001];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u) {
    int prev = u;
    u = find(u);
    parent[prev] = u-1;
    parent[u] = u-1;
    ans++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> G >> P;
    for (int i=1;i<=G;i++) {
        parent[i] = i;
    }

    for (int i=0;i<P;i++) {
        int g;
        cin >> g;

        if (find(g) == 0) break;
        else merge(g);
    }

    cout << ans << endl;
    return 0;
}
