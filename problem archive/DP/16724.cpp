#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M,K,ans;
int arr[30001];
int dp[3001];
bool visit[30001];
vector<int> v[30001];
vector<pair<int,int>> set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i=1;i<=N;i++) {
        if (visit[i] == true) continue;

        int child = 0;
        int candy = 0;

        queue<int> q;
        q.push(i);
        child++;
        candy += arr[i];
        visit[i] = true;

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i=0;i<v[x].size();i++) {
                int nx = v[x][i];
                if (visit[nx] == true) continue;
                q.push(nx);
                child++;
                candy += arr[nx];
                visit[nx] = true;
            }
        }

        set.push_back({child,candy});
    }

    int ss = set.size();

    for (int j = 0;j<ss;j++) {
        for (int i = K - 1; i >= 0; i--) {
            if(i - set[j].first >= 0){
                dp[i] = max(dp[i], dp[i - set[j].first] + set[j].second);
                ans = max(ans,dp[i]);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
