#include <iostream>
#include <vector>
#include <queue>
#define INF 100000001
using namespace std;
int T,N,K,W;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> K;

        vector<int> v[N+1];
        int build[N+1] = {0,};
        int ismid[N+1] = {0,};

        priority_queue<pair<int,int>> pq;
        int time[N+1];

        for (int i=1;i<=N;i++) {
            cin >> build[i];
            time[i] = INF;
        }

        while(K--) {
            int a,b;
            cin >> a >> b;
            ismid[b]++;

            v[a].push_back(b);
        }

        cin >> W;

        for (int i=1;i<=N;i++) {
            if (ismid[i] == 0) {
                pq.push({-build[i],i});
                time[i] = build[i];
            }
        }

        while(!pq.empty()) {
            int x = pq.top().second;
            int t = -pq.top().first;

            pq.pop();

            if (x == W) {
                cout << t << '\n';
                break;
            }

            for (int i=0;i<v[x].size();i++) {
                int nx = v[x][i];
                int nt = build[nx]; 

                if (ismid[nx] == 1) {
                    if (time[nx] > nt + t) {
                        time[nx] = nt + t;
                        pq.push({-time[nx], nx});
                    }
                }
                else {
                    ismid[nx]--;
                }
            }
        }
    }
    return 0;
}
