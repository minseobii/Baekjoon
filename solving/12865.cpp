#include <iostream>
using namespace std;
int N,K;
int V[100000];
int W[100000];
int DP[100000][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        int w,v;
        cin >> w >> v;
        V[i] = v;
        W[i] = w;
    }

    for (int w=1;w<=K;w++) {
        for (int i=1;i<=N;i++) {
            if (w >= W[i]) {
                DP[w][i] = max(DP[w][i-1], DP[w-W[i]][i-1] + V[i]);
            }
            else {
                DP[w][i] = DP[w][i-1];
            }
        }
    }
    cout << DP[K][N] << endl;
    return 0;
}
