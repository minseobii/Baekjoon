#include <iostream>
using namespace std;
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        int arr[N][2] = {0,};
        int DP[N][3] = {0,};

        for (int i=0;i<N;i++) {
            cin >> arr[i][0];
        }
        for (int i=0;i<N;i++) {
            cin >> arr[i][1];
        }

        for (int i=0;i<N;i++) {
            if (i == 0) {
                DP[i][0] = arr[i][0];
                DP[i][1] = arr[i][1];
                DP[i][2] = 0;
            }
            else {
                DP[i][0] = max(DP[i-1][1], DP[i-1][2]) + arr[i][0];
                DP[i][1] = max(DP[i-1][0], DP[i-1][2]) + arr[i][1];
                DP[i][2] = max(DP[i-1][0], DP[i-1][1]);
            }
        }
        cout << max(DP[N-1][0], DP[N-1][1]) << '\n';
    }
    return 0;
}
