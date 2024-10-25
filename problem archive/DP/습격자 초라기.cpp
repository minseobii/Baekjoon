#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define INF 20001
using namespace std;
int T,N,W,arr[10000][2];
int DP[10000][3];

int dp() {
    for (int i=0;i<N;i++) {
        if (i == 0) {
            if (arr[i][0] + arr[i][1] <= W) DP[0][0] = 1;
            else DP[0][0] = 2;
            DP[0][1] = 1;
            DP[0][2] = 1;
        }
        for (int k=0;k<3;k++) {
            if (k == 0) { // 둘다 커버 
                int temp = INF;
                if (arr[i-1][0] + arr[i][0] <= W && arr[i-1][1] + arr[i][1] <= W){
                    if (i == 1) temp = min(temp, 2);
                    else temp = min(temp, DP[i-2][0]+2);
                }
                if (arr[i][0] + arr[i][1] <= W) temp = min(temp, DP[i-1][0]+1);
                else temp = min(temp, DP[i-1][0]+2);

                if (arr[i-1][0] + arr[i][0] <= W) temp = min(temp, DP[i-1][2]+2);
                else temp = min(temp, DP[i-1][2]+3);

                if (arr[i-1][1] + arr[i][1] <= W) temp = min(temp, DP[i-1][1]+2);
                else temp = min(temp, DP[i-1][1]+3);
                DP[i][k] = temp;
            }
            else if (k == 1) { // 위만 커버 
                int temp = INF;
                temp = min(temp, DP[i-1][0]+1);

                temp = min(temp, DP[i-1][1]+2);

                if (arr[i-1][0] + arr[i][0] <= W) temp = min(temp, DP[i-1][2]+1);
                else temp = min(temp, DP[i-1][2]+2);
                DP[i][k] = temp;
            }
            else if (k == 2) { // 아래만 커버
                int temp = INF;
                temp = min(temp, DP[i-1][0]+1);

                temp = min(temp, DP[i-1][2]+2);

                if (arr[i-1][1] + arr[i][1] <= W) temp = min(temp, DP[i-1][1]+1);
                else temp = min(temp, DP[i-1][1]+2);
                DP[i][k] = temp;
            }
        }
        //cout << i << ' ' << DP[i][0] << ' ' << DP[i][1] << ' ' << DP[i][2] << endl;
    }
    //cout << endl;
    return DP[N-1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N >> W;
        memset(arr,0,sizeof(arr));
        for (int i=0;i<2;i++) {
            for (int j=0;j<N;j++) {
                cin >> arr[j][i];
            }
        }

        int ans = INF;
        for (int k=0;k<4;k++) {
            if (k == 0) { // 연결 x
                memset(DP,0,sizeof(DP));
                int temp = dp();
                ans = min(ans, temp);
            }
            else if (k == 1) { // 위만 0, N-1 연결
                if (N == 1 || arr[0][0] + arr[N-1][0] > W) continue;
                pair<int,int> memo = {arr[0][0], arr[N-1][0]};
                arr[0][0] = W;
                arr[N-1][0] = W;
                memset(DP,0,sizeof(DP));
                int temp = dp()-1;
                ans = min(ans, temp);
                arr[0][0] = memo.first;
                arr[N-1][0] = memo.second;
            }
            else if (k == 2) { // 아래만 0, N-1 연결
            if (N == 1 || arr[0][1] + arr[N-1][1] > W) continue;
                pair<int,int> memo = {arr[0][1], arr[N-1][1]};
                arr[0][1] = W;
                arr[N-1][1] = W;
                memset(DP,0,sizeof(DP));
                int temp = dp()-1;
                ans = min(ans, temp);
                arr[0][1] = memo.first;
                arr[N-1][1] = memo.second;
            }
            else if (k == 3) { // 위, 아래 모두 0, N-1 연결
            if (N == 1 || arr[0][0] + arr[N-1][0] > W || arr[0][1] + arr[N-1][1] > W) continue;
                arr[0][0] = W;
                arr[N-1][0] = W;
                arr[0][1] = W;
                arr[N-1][1] = W;
                memset(DP,0,sizeof(DP));
                int temp = dp()-2;
                ans = min(ans, temp);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
