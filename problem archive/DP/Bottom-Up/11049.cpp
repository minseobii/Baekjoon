#include <iostream>
using namespace std;
int N;
long long DP[501][501];
int arr[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        int a,b;
        cin >> a >> b;
        if (i == 1) {
            arr[0] = a;
            arr[1] = b;
        }
        else {
            arr[i] = b;
        }
    }

    for (int i=2;i<=N;i++) {
        int s = 0;
        while(s+i <= N) {
            if (i == 2) {
                DP[s][s+i] = arr[s]*arr[s+1]*arr[s+2];
            }
            else {
                DP[s][s+i] = min(DP[s+1][s+i]+(arr[s]*arr[s+1]*arr[s+i])
                                ,DP[s][s+i-1]+(arr[s]*arr[s+i-1]*arr[s+i]));
                for (int j=2;j<i;j++) {
                    DP[s][s+i] = min(DP[s][s+i], DP[s][s+j]+DP[s+j][s+i]+(arr[s]*arr[s+j]*arr[s+i]));
                }
            }
            s++;
        }
    }
    cout << DP[0][N] << endl;
    return 0;
}
