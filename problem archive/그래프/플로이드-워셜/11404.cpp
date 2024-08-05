#include <iostream>
#define INF 10000001
using namespace std;
int N,M;
int DP[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> M;
    for (int i=0;i<=N;i++) {
        for (int j=0;j<=N;j++) {
            if (i == j) {
                DP[i][j] = 0;
            }
            else {
                DP[i][j] = INF;
            }
        }
    }
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        DP[a][b] = min(DP[a][b], c);
    }

    for (int i=1;i<=N;i++) {
        for (int a=1;a<=N;a++) {
            for (int b=1;b<=N;b++) {
                if (a == i || b == i) {
                    continue;
                }
                else {
                    DP[a][b] = min(DP[a][b], DP[a][i]+DP[i][b]);
                }
            }
        }
            
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (DP[i][j] == INF) {
                cout << 0 << ' ';
            }
            else {
                cout << DP[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
