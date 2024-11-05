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
using namespace std;
int N,M,sum,A[31];
bool DP[15001][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> A[i];
        sum += A[i];
    }
    
    cin >> M;
    for (int a=0;a<M;a++) {
        int k;
        cin >> k;
        if (sum < k) {
            cout << "N ";
            continue;
        }

        memset(DP,0,sizeof(DP));
        fill(DP[sum],DP[sum]+N+1,1);
        for (int i=sum-1;i>=k;i--) {
            for (int j=1;j<=N;j++) {
                if (2*A[j]+i <= sum && DP[2*A[j]+i][j-1]) DP[i][j] = true;
                if (A[j]+i <= sum && DP[A[j]+i][j-1]) DP[i][j] = true;
                DP[i][j] |= DP[i][j-1];
            }
        }

        if (DP[k][N]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}
