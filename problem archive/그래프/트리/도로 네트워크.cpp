#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1000001
using namespace std;

struct PAIR {
    int x,Min,Max;
};

int N,M,level[100001];
PAIR parent[100001][18];
vector<pair<int,int>> v[100001];

void dfs(int x, int p, int w, int l) {
    if (x != 1) parent[x][0] = {p,w,w};
    level[x] = l;
    for (int i=1;i<18;i++) {
        PAIR mid = parent[x][i-1];
        PAIR end = parent[mid.x][i-1];
        parent[x][i] = {end.x, min(mid.Min, end.Min), max(mid.Max, end.Max)};
        //cout << x << ' ' <<parent[x][i].x << ' ' << parent[x][i].Min << ' ' << parent[x][i].Max << endl;
    }

    for (pair<int,int> k : v[x]) {
        if (k.first == p) continue;
        dfs(k.first, x, k.second, l+1);
    }
}

void solve(int d, int e) {
    int Min = INF;
    int Max = -INF;
    PAIR tempd;
    PAIR tempe;

    if (level[d] != level[e]) {
        if (level[d] < level[e]) swap(d,e);
        for (int i=17;i>=0;i--) {
            if (level[d] - (1 << i) >= level[e]) {
                Min = min(Min, parent[d][i].Min);
                Max = max(Max, parent[d][i].Max);
                d = parent[d][i].x;
            }
        }
    }
    if (d == e) {
        cout << Min << ' ' << Max << '\n';
        return;
    }

    for (int i=17;i>=0;i--) {
        if (parent[d][i].x != parent[e][i].x) {
            Min = min(Min, min(parent[d][i].Min, parent[e][i].Min));
            Max = max(Max, max(parent[d][i].Max, parent[e][i].Max));
            d = parent[d][i].x;
            e = parent[e][i].x;
        }
        tempd = parent[d][i];
        tempe = parent[e][i];
    }

    Min = min(Min, min(tempd.Min, tempe.Min));
    Max = max(Max, max(tempd.Max, tempe.Max));
    cout << Min << ' ' << Max << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for (int i=0;i<18;i++) {
        parent[0][i] = {0, INF, -INF};
        parent[1][i] = {0, INF, -INF};
    }
    dfs(1,0,0,1);

    cin >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        solve(a,b);
    }
    return 0;
}
