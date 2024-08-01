#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V,E,K;

struct PAIR {
    int i,w;
};

int main(){
    cin >> V >> E;
    cin >> K;
    vector<PAIR> v[V+1];
    for (int i=0;i<E;i++) {
        int s,e,w;
        cin >> s >> e >> w;
        v[s].push_back({e,w});
    }

    int ans[V+1];
    for (int i=0;i<=V;i++) {
        ans[i] = -1;
    }

    priority_queue<pair<int,int>> q;        
    q.push({0,K});
    ans[K] = 0;

    while (!q.empty()) {
        int x = q.top().second;
        int w = -q.top().first;
        q.pop();
        for (int k=0;k<v[x].size();k++) {
            int nx = v[x][k].i;
            int nw = v[x][k].w;

            if (ans[nx] == -1){
                ans[nx] = w + nw;
                q.push({-ans[nx], nx});
            }
            else if (ans[nx] > w + nw) {
                ans[nx] = w + nw;
                q.push({-ans[nx], nx});
            }
        }
    }
    for (int i=1;i<=V;i++) {
        if (ans[i] == -1) {
            cout << "INF" << '\n';
        }
        else {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}