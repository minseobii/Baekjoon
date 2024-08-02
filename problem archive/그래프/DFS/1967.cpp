#include <iostream>
#include <vector>
using namespace std;
int N;
vector<pair<int,int>> v[10001];
int Point=0;

int visit[10001];
int vertex=0;
int dis=0;
void DFS(int a,int w) {
    for (int i=0;i<v[a].size();i++) {
        if (visit[v[a][i].first] == 0) {
            visit[v[a][i].first] = 1;
            if (dis < v[a][i].second + w) {
                dis = v[a][i].second + w;
                vertex = v[a][i].first;
            }
            DFS(v[a][i].first, v[a][i].second + w);
            visit[v[a][i].first] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    
    for (int i=0;i<N-1;i++) {
        int p,c,w;
        cin >> p >> c >> w;
        v[p].push_back({c,w});
        v[c].push_back({p,w});
    }

    vertex = 0;
    dis = 0;
    visit[1] = 1;
    DFS(1,0);
    visit[1] = 0;

    Point = vertex;

    vertex = 0;
    dis = 0;
    visit[Point] = 1;
    DFS(Point, 0);
    visit[Point] = 0;
    cout << dis << endl;
    return 0;
}
