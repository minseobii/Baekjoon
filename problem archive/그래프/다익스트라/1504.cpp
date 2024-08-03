#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000 
using namespace std;
int N,E,v1,v2;
int ans;
vector<pair<int,int>> v[801];
int Dis[3][801];

void BST(int start, int idx) {
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    Dis[idx][start] = 0;
    int ReturnValue = 0;

    while(!pq.empty()) {
        int a = pq.top().second;
        int w = pq.top().first;

        pq.pop();

        for (int i=0;i<v[a].size();i++) {
            int na = v[a][i].first;
            int nw = v[a][i].second;

            if (Dis[idx][na] > nw + w) {
                Dis[idx][na] = nw + w;
                pq.push({Dis[idx][na], na});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> E;
    for (int i=0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> v1 >> v2;
    for (int i=0;i<3;i++) {
        for (int j=0;j<801;j++) {
            Dis[i][j] = INF;
        }
    }
    BST(1,0);
    BST(v1,1);
    BST(N,2);

    int ans = min(Dis[0][v1]+Dis[2][v2], Dis[0][v2]+Dis[2][v1]) + Dis[1][v2];
    if ((Dis[0][v1] == INF || Dis[2][v2] == INF) && (Dis[0][v2] == INF || Dis[2][v1] == INF) || (Dis[1][v2] == INF)) {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}
