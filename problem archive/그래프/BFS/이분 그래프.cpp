#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    while(K--) {
        int V,E;
        bool ans = true;
        cin >> V >> E;

        vector<int> edge[20001];
        int parent[20001] = {0,};

        for (int i=0;i<E;i++) {
            int a,b;
            cin >> a >> b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        queue<int> q;
        for (int i=1;i<=V;i++) {
            if (parent[i] != 0) continue;

            q.push(i);
            parent[i] = 1;

            while(!q.empty()) {
                int x = q.front();
                q.pop();

                for (int k=0;k<edge[x].size();k++) {
                    int nx = edge[x][k];
                    if (parent[nx] == parent[x]) {
                        ans = false;
                        break;
                    }
                    if (parent[nx] != 0) continue;

                    parent[nx] = -parent[x];
                    q.push(nx);
                }
                if (ans == false) break;
            }
            if (ans == false) break;
        }
        if (ans == true) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
