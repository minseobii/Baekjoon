#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;

vector<pair<int,int>> edge[40001];
bool visit[40001];
int level[40001];
pair<int,int> parent[40001][17];

int subarr[17];

void DFS(int x, int depth) {
    visit[x] = true;
    level[x] = depth;

    for (int i=0;i<edge[x].size();i++) {
        int nx = edge[x][i].first;
        int w = edge[x][i].second;
        if (visit[nx]) continue;
        
        visit[nx] = true;
        parent[nx][0] = {x,w};
        DFS(nx,depth+1);
    }
} 

void init() {
    for (int k = 1;k<17;k++) {
        for (int i=1;i<=N;i++) {
            parent[i][k] = {parent[parent[i][k-1].first][k-1].first,parent[parent[i][k-1].first][k-1].second 
                            + parent[i][k-1].second};
        }
    }

    subarr[0] = 1;
    for (int i=1;i<17;i++) {
        subarr[i] = subarr[i-1] * 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    level[0] = 0;
    DFS(1,1);
    init();

    cin >> M;
    for (int i=0;i<M;i++) {
        int v1,v2;
        int ans = 0;
        cin >> v1 >> v2;
        
        if (level[v1] < level[v2]) swap(v1,v2);
        for (int i=16;i>=0;i--) {
            if (level[parent[v1][i].first] >= level[v2]) {
                ans += parent[v1][i].second;
                v1 = parent[v1][i].first;
            }
        }


        if (v1 == v2) {
            cout << ans << '\n'; 
            continue;
        }

        int temp = 0;
        for (int i=16;i>=0;i--) {
            if (parent[v1][i].first != parent[v2][i].first) {
                ans += parent[v1][i].second + parent[v2][i].second;
                v1 = parent[v1][i].first;
                v2 = parent[v2][i].first;
            }
            temp = parent[v1][i].second + parent[v2][i].second;
        }
        cout << ans + temp << '\n'; 
    } 
    return 0;
}
