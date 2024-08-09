#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<pair<int,int>> v[100001];
int visit[100001];

int ans;

int BFS(int i){
    for (int j=0;j<=N;j++) {
        visit[j] = 0;
    }
    int MaxV=0;
    queue<pair<int, int>> q;          
    q.push({i,0});

    visit[i] = 1;

    while (!q.empty()) {

        int x = q.front().first;
        int w = q.front().second;
        q.pop();

        for (int j=0;j<v[x].size();j++) {
            int nx = v[x][j].first;
            int nw = v[x][j].second;

            if (visit[nx] == 0) {
                visit[nx] = nw + w;
                q.push({nx, visit[nx]});

                if (visit[nx] > ans) {
                    ans = visit[nx];
                    MaxV = nx;
                }
            }
        }
    }
    return MaxV;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    for (int i=0;i<N;i++) {
        int s;
        cin >> s;

        int temp;
        cin >> temp;
        while(temp != -1) {
            int w;
            cin >> w;

            v[s].push_back({temp, w});
            cin >> temp;
        }
    }

    BFS(BFS(1));

    cout << ans << endl;
    return 0;
}
