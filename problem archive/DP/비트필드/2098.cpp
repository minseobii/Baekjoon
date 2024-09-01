#include <iostream>
#define INF 20000000
using namespace std;
int N;
int city = 1;
int ans = INF;
int arr[16][16];
int DP[16][16][65536];

int dp(int s, int e, int bit) {
    if (DP[s][e][bit] == -1) return -1;
    if (s == e) {
        if (bit == (1 << s)) return 0;
        else if (bit != (city-1)) return -1;
    }
    if (!(1<<s & bit) || !(1<<e & bit)) return -1;

    if (DP[s][e][bit] < INF) return DP[s][e][bit];

    int count = 0;

    for (int i=0;i<N;i++) {
        int temp = dp(s,i,bit & (~(1<<e)));
        if (temp == -1 || arr[i][e] == 0) {
            count++;
            continue;
        }
        DP[s][e][bit] = min(DP[s][e][bit], temp + arr[i][e]);
    }

    if (count == N) DP[s][e][bit] = -1;
    return DP[s][e][bit];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<N;i++) {
        city *= 2;
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
            for (int k=0;k<city;k++) {
                DP[i][j][k] = INF;
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i == j) continue;
            int temp = dp(i,j,city-1);
            if (temp == -1 || arr[j][i] == 0) continue;
            ans = min(ans, temp + arr[j][i]);
        }
    }

    cout << ans << endl;
    return 0;
}
