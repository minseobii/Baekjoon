#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1000000000
using namespace std;
int N,ans;
int E[100001];
int parent[100001][18];
int dis[100001];
vector<pair<int,int>> v[100001];

void dfs(int x, int p, int w) {
    parent[x][0] = p;
    dis[x] = w;

    for (int k=1;k<18;k++) {
        parent[x][k] = parent[parent[x][k-1]][k-1];
    } 

    for (int i=0;i<v[x].size();i++) {
        if (v[x][i].first == p) continue;
        dfs(v[x][i].first, x, w + v[x][i].second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> E[i];
    }
    for (int i=0;i<N-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    dfs(1,0,0);
    for (int i=1;i<=N;i++) {
        if (dis[i] <= E[i]) {
            cout << 1 << '\n';
            continue;
        }

        int x = i;
        int ans = x;
        for (int k=17;k>=0;k--) {
            if (dis[i] - dis[parent[x][k]] <= E[i]) {
                x = parent[x][k];
            }
            ans = x;
        }
        cout << ans << '\n';
    }
    return 0;
}
