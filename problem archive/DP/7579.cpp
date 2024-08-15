#include <iostream>
using namespace std;
int N,M,ans;
int memory[101];
int cost[101];
int DP[10002][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        cin >> memory[i];
    }
    for (int i=1;i<=N;i++) {
        cin >> cost[i];
    }

    for (int i=1;i<=10001;i++) {
        for (int j=1;j<=N;j++) {
            int temp = DP[i][j-1];
            if (cost[j] == i-1) temp = max(temp, memory[j]);
            if (cost[j] <= i-1) temp = max(temp, DP[i-cost[j]][j-1] + memory[j]);
            DP[i][j] = temp;
        }
        if (DP[i][N] >= M) {
            ans = i-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
