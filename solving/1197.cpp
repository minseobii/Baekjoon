#include <iostream>
#include <vector>
#include <queue>
#define INF 1000001
using namespace std;

int V,E,ans;
vector<pair<int,int>> v[10001];
vector<int> MST;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i=0;i<E;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    MST.push_back(1);
    int e = 0;
    while(e < V-1) {
        int MinE = INF;
        int MinV = -1;
        for (int i=0;i<MST.size();i++) {
            int node = MST[i];
            for (int j=0;j<v[node].size();j++) {
                int find = 0;
                for (int k=0;k<MST.size();k++) {
                    if (v[node][j].first == MST[k]) {
                        find = 1;
                        break;
                    }
                }
                if (find == 0 && MinE > v[node][j].second) {
                    MinE = v[node][j].second;
                    MinV = v[node][j].first;
                }
            }
        }
        MST.push_back(MinV);
        ans += MinE;
        e++;
    }

    cout << ans << endl; 
    return 0;
}
