#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N,V;

vector<pair<int,int>> v[2];
map<int,bool> visit[2];
int ans[2];

bool check(int x, int y, int idx) {
    if (visit[idx][x+y] || visit[idx][x-y-N]) return false;
    return true;
}

void cal(int n,int k, int idx) {
    if (n == v[idx].size()) {
        ans[idx] = max(ans[idx], k);
        return;
    }

    for (int i=n;i<v[idx].size();i++) {
        int x = v[idx][i].first;
        int y = v[idx][i].second;
        
        if (check(x,y,idx)){
            visit[idx][x+y] = true;
            visit[idx][x-y-N] = true;
            cal(i+1,k+1,idx);
            visit[idx][x+y] = false;
            visit[idx][x-y-N] = false;
        }
        else if (i+1 == v[idx].size()) ans[idx] = max(ans[idx], k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int temp;
            cin >> temp;
            if (temp) {
                if ((i+j) % 2 == 0) v[0].push_back({i,j});
                else v[1].push_back({i,j});
            }
        }
    }

    cal(0,0,0);
    cal(0,0,1);

    cout << ans[0] + ans[1] << endl;
    return 0;
}
