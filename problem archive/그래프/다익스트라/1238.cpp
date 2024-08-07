#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,X;
int ans; 
vector<pair<int, int>> v[1001][2]; 
int visit[1001][2];

void Dijkstra(int k) {
    priority_queue<pair<int,int>> pq;
    for (int i=0;i<v[X][k].size();i++) {
        int n = v[X][k][i].first;
        int w = v[X][k][i].second;
        pq.push({w, n});
        visit[n][k] = w;
    }

    while(!pq.empty()) {
        int x = pq.top().second;
        int w = pq.top().first;

        pq.pop();

        for (int i=0;i<v[x][k].size();i++) {
            int nx = v[x][k][i].first;
            int nw = v[x][k][i].second;

            if (visit[nx][k] == 0 || visit[nx][k] > w+nw) {
                if (nx != X){
                    visit[nx][k] = w + nw;
                    pq.push({visit[nx][k], nx});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a][0].push_back({b,c});
        v[b][1].push_back({a,c});
    }

    Dijkstra(0);
    Dijkstra(1);

    for (int i=1;i<=N;i++) {
        ans = max(ans, visit[i][0]+visit[i][1]);
    }

    cout << ans << endl;
    return 0;
}
