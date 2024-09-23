#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 10000001
using namespace std;
int N,M,S,D;
vector<pair<int,int>> v[500];
vector<int> bt[500];
priority_queue<pair<int,int>> pq;
queue<int> q;
int Dis[500];
int NearlyDis[500];
bool visit[500];
bool shortest_path[500][500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    while(N != 0 && M != 0) {
        cin >> S >> D;
        for (int i=0;i<500;i++) { //init
            Dis[i] = INF;
            v[i].clear();
            bt[i].clear();
            Dis[i] = INF;
            NearlyDis[i] = INF;
            visit[i] = false;
            for (int j=0;j<500;j++) {
                shortest_path[i][j] = false;
            }
        }
        for (int i=0;i<M;i++) {
            int U,V,P;
            cin >> U >> V >> P;
            v[U].push_back({V,P});
        }

        pq.push({0,S});
        Dis[S] = 0;

        while(!pq.empty()) {
            int x = pq.top().second;
            int w = -pq.top().first;
            pq.pop();
            if (w > Dis[x]) continue;

            for (int i=0;i<v[x].size();i++) {
                int nx = v[x][i].first;
                int nw = v[x][i].second;
                if (w + nw < Dis[nx]) {
                    Dis[nx] = w + nw;
                    pq.push({-Dis[nx],nx});
                    bt[nx].clear();
                    bt[nx].push_back(x);
                }
                else if (w + nw == Dis[nx]) {
                    bt[nx].push_back(x);
                }
            }
        }

        if (Dis[D] == INF) { // 최단경로 X
            cout << -1 << '\n';
            cin >> N >> M;
            continue;
        }   
        else {
            q.push(D);
            visit[D] = true;
            while(!q.empty()) {
                int k = q.front();
                q.pop();

                if (k == S) continue;

                for (int i=0;i<bt[k].size();i++) {
                    int nk = bt[k][i];
                    shortest_path[nk][k] = true;
                    if (visit[nk]) continue;
                    visit[nk] = true;
                    q.push(nk);
                }
            }


            pq.push({0,S});
            NearlyDis[S] = 0;
            while(!pq.empty()) {
                int x = pq.top().second;
                int w = -pq.top().first;
                pq.pop();
                if (w > NearlyDis[x]) continue;

                for (int i=0;i<v[x].size();i++) {
                    int nx = v[x][i].first;
                    int nw = v[x][i].second;
                    if (shortest_path[x][nx] == true) continue;

                    if (w + nw < NearlyDis[nx]) {
                        NearlyDis[nx] = w + nw;
                        pq.push({-NearlyDis[nx],nx});
                    }
                }
            }

            if (NearlyDis[D] == INF) cout << -1 << '\n';
            else cout << NearlyDis[D] << '\n';
            cin >> N >> M;
        }
    }
    return 0;
}
