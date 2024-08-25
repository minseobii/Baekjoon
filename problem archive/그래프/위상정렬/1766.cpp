#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int enter[32001];
vector<int> v[32001];
priority_queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        enter[b]++;
    }
    for (int i=1;i<=N;i++) {
        if (enter[i] == 0) {
            q.push(-i);
        }
    }

    while(!q.empty()) {
        int x = -q.top();
        q.pop();

        cout << x << ' ';

        for (int i=0;i<v[x].size();i++) {
            int nx = v[x][i];

            if (--enter[nx] == 0) {
                q.push(-nx);
            }
        }
    }
    cout << '\n';
    return 0;
}
