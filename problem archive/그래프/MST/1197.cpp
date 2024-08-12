#include <iostream>
#include <vector>
#include <queue>
#define INF 1000001
using namespace std;

int V,E,ans;
priority_queue<pair<int,int>> pq;
vector<pair<int,int>> v[10001];
int Add[10001];

void AddEdge(int k) {
    for (int i=0;i<v[k].size();i++) {
        if (Add[v[k][i].first] == 0) {
            pq.push({-v[k][i].second, v[k][i].first});
        }
    }
}

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
    
    Add[1] = 1;
    AddEdge(1);
    int e = 0;
    while(e < V-1) {
        while (1) {
            int a,w;
            a = pq.top().second;
            w = -pq.top().first;

            pq.pop();

            if (Add[a] == 0) {
                Add[a] = 1;
                AddEdge(a);
                ans += w;
                e++;
                break;
            }
        }
    }

    cout << ans << endl; 
    return 0;
}
