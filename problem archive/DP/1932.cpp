#include <iostream>
using namespace std;
int N;
int arr[500][500];
int DP[500][500];
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<=i;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<=i;j++) {
            if (i == 0) {
                DP[i][j] = arr[i][j];
            }
            else{
                if (j == 0) {
                    DP[i][j] = arr[i][j] + DP[i-1][j];
                }
                else if (j == i) {
                    DP[i][j] = arr[i][j] + DP[i-1][j-1];
                }
                else {
                    DP[i][j] = arr[i][j] + max(DP[i-1][j],DP[i-1][j-1]);
                }
            }
        }
    }
    for (int i=0;i<N;i++) {
        ans = max(ans, DP[N-1][i]);
    }
    cout << ans << endl;
    return 0;
}
