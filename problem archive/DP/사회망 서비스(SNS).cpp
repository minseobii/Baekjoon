#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,num,ans;

vector<int> v[1000001];
int DP[1000001][2];
bool visit[1000001];

void dp(int x) {
    visit[x] = true;
    DP[x][1] = 1;

    for (int i=0;i<v[x].size();i++) {
        if (visit[v[x][i]]) continue;
        dp(v[x][i]);

        DP[x][0] += DP[v[x][i]][1];
        DP[x][1] += min(DP[v[x][i]][0],DP[v[x][i]][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dp(1);

    cout << min(DP[1][0], DP[1][1]) << endl;
    return 0;
}
