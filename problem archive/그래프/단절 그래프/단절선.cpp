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
int V,E,id,ans,parent[100001];
vector<int> v[100001];
map<pair<int,int>, bool> m;

pair<int,int> swap_m(int a, int b) {
    if (b < a) swap(a,b);
    return {a,b};
}

int DFS(int x, int p) {
    parent[x] = ++id;
    int ret = id;
    for (int k : v[x]) {
        if (k == p) continue;
        if (parent[k] == 0) {
            int dfs = DFS(k, x);
            ret = min(ret, dfs);
            if (dfs > parent[x]) m[swap_m(k,x)] = true;
        }
        else ret = min(ret, parent[k]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i=0;i<E;i++) {
        int a,b;
        cin >> a >> b;
        m[swap_m(a,b)] = false;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(1,0);

    for (auto x : m) {
        if (x.second) ans++;
    }
    cout << ans << '\n';
    for (auto x : m) {
        if (x.second) cout << x.first.first << ' ' << x.first.second << '\n';
    }

    return 0;
}
