#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001
using namespace std;
int N,M,A,B;
vector<pair<int,int>> v[1001];
vector<int> ans[1001];
int Distance[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M; 
    for (int i=1;i<=N;i++) {
        Distance[i] = INF;
    }
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        v[a].push_back({b,c});
    }
    cin >> A >> B;


    priority_queue<pair<int,int>> pq;

    pq.push({0,A});
    ans[A].push_back(A);
    Distance[A] = 0;
    
    while(!pq.empty()) {
        int x = pq.top().second;
        int d = -pq.top().first;

        pq.pop();

        if (d > Distance[x]) {
            continue;
        }

        for (int i=0;i<v[x].size();i++) {
            int nx = v[x][i].first;
            int nd = v[x][i].second;

            if (Distance[nx] > nd + d) {
                Distance[nx] = nd + d;
                pq.push({-Distance[nx], nx});

                ans[nx].clear();
                for (int j=0;j<ans[x].size();j++) {
                    ans[nx].push_back(ans[x][j]);
                }
                ans[nx].push_back(nx);
            }
        }
    }
    cout << Distance[B] << '\n';
    cout << ans[B].size() << '\n';
    for (int i=0;i<ans[B].size();i++) {
        cout << ans[B][i] << ' ';
    }
    cout << '\n';
    return 0;
}
