#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int end[1001];
vector<int> v;
vector<int> ans;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int m,k,s,e;
        cin >> m;
        for (int j=0;j<m;j++) {
            cin >> k;
            if (j == 0) s=k;
            else {
                v[s].push_back(k);
                s=k;
                end[k]++;
            }
        }
    }

    for (int i=1;i<=N;i++) {
        if (end[i] == 0) {
            q.push(i);
            ans.push_back(i);
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i=0;i<v[x].size();i++) {
            int nx = v[x][i];
            if (--end[nx]) ans.push_back(nx);
        }
    }

    for (int i=1;i<=N;i++) {
        if (end[i]) {
            cout << 0 << '\n';
        }
        return 0;
    }
    
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
