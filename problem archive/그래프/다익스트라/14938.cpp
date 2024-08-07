#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M,L,ans;
int item[101];
vector<pair<int,int>> v[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> L;
    for (int i=1;i<=N;i++) {
        cin >> item[i];
    }
    for (int i=0;i<L;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    

    for (int i=1;i<=N;i++) {
        int visit[101] = {0,};

        priority_queue<pair<int, int>> pq;  

        pq.push({0,i});
        visit[i] = 1;

        while (!pq.empty()) {
            int x = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            for (int j=0;j<v[x].size();j++) {
                int nx = v[x][j].first;
                int nw = v[x][j].second;

                if ((visit[nx] == 0 || visit[nx] > nw+w) && nw+w <= M) {
                    visit[nx] = nw + w;
                    pq.push({visit[nx], nx});
                }
            }
        }
        int tempans=0;
        for (int k=1;k<=N;k++) {
            if (visit[k]) {
                tempans += item[k];
            }
        }
        ans = max(tempans, ans);
    }
    cout << ans << endl;;
    return 0;
}