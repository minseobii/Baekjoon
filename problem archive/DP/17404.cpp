#include <iostream>
#define INF 1000001
using namespace std;
int N,ans;
int RDP[1001][3];
int GDP[1001][3];
int BDP[1001][3];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        int r,g,b;
        cin >> r >> g >> b;
        for (int j=0;j<3;j++) {
            RDP[i][j] = INF;
            GDP[i][j] = INF;
            BDP[i][j] = INF;
        }

        if (i == 1) {
            RDP[i][0] = r;
            GDP[i][1] = g;
            BDP[i][2] = b;
        }
        else {
            for (int j=0;j<3;j++) {
                RDP[i][j] = min(min(GDP[i-1][j], BDP[i-1][j]) + r, INF);
                GDP[i][j] = min(min(RDP[i-1][j], BDP[i-1][j]) + g, INF);
                BDP[i][j] = min(min(RDP[i-1][j], GDP[i-1][j]) + b, INF);
            }
        }
    }

    int tempR,tempG,tempB;
    tempR = min(RDP[N][1], RDP[N][2]);
    tempG = min(GDP[N][0], GDP[N][2]);
    tempB = min(BDP[N][0], BDP[N][1]);
    ans = min(tempR,min(tempG,tempB));
    cout << ans << endl;
    return 0;
}
