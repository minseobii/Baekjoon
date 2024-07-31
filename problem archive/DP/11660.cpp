#include <iostream>
using namespace std;
int N, M;
int DP[1030][1030];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            int input;
            cin >> input;
            if (i == 1) {
                if (j == 1) {
                    DP[i][j] = input;
                }
                else {
                    DP[i][j] = DP[i][j-1] + input;
                }
            }
            else if (j == 1) {
                DP[i][j] = DP[i-1][j] + input;
            }
            else {
                DP[i][j] = DP[i][j-1] + DP[i-1][j] - DP[i-1][j-1] + input;
            }
        }    
    }

    for (int i=0;i<M;i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << DP[x2][y2] - DP[x2][y1-1] - DP[x1-1][y2] + DP[x1-1][y1-1] << '\n'; 
    }
    return 0;
}
