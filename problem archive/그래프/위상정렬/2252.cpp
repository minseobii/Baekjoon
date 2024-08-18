#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int last[32001];
vector<int> v[32001];
queue<pair<int,int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    while(M--) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        last[b]++;
    }

    for (int i=1;i<=N;i++) {
        if (last[i] == 0) {
            q.push({i,0});
            cout << i << ' ';
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int w = q.front().second;

        q.pop();

        for (int i=0;i<v[x].size();i++) {
            int nx = v[x][i];
            int nw = w + 1;

            if (--last[nx] == 0) {
                q.push({nx, nw});
                cout << nx << ' ';
            }
        }
    }
    cout << endl;

    return 0;
}
