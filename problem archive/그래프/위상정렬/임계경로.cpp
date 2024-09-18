#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M,S,E;

vector<pair<int,int>> edge[10001];
vector<int> path[10001];
int DP[10001];
bool visit[10001];
int ans;

int dp(int x) {
    if (DP[x] || x == S) return DP[x];

    int time = 0;
    for (int i=0;i<edge[x].size();i++) {
        int t = dp(edge[x][i].first);
        if (t+edge[x][i].second > time) {
            time = t+edge[x][i].second;
        }
    }

    for (int i=0;i<edge[x].size();i++) {
        int t = dp(edge[x][i].first);
        if (t+edge[x][i].second == time) {
            path[x].push_back(edge[x][i].first);
        }
    }

    DP[x] = time;
    return DP[x];
}

void dfs(int x) {
    for (int i=0;i<path[x].size();i++) {
        ans++;
        if (visit[path[x][i]] == false) {
            visit[path[x][i]] = true;
            dfs(path[x][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[b].push_back({a,c});
    }
    cin >> S >> E;

    DP[S] = 0;
    dp(E);
    dfs(E);

    cout << DP[E] << '\n' << ans << '\n';
    return 0;
}
