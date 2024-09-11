#include <iostream>
using namespace std;
int N;
int visit[10];
int subarr[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int DP[10][2];
int ans[10];

int init() {
    for (int i=1;i<10;i++) {
        if (i == 1) {
            DP[i][0] = 1;
            DP[i][1] = 1;
        }
        else {
            DP[i][0] = (9 * DP[i-1][1]) + DP[i-1][0] + i - 1;
            DP[i][1] = (10 * DP[i-1][1]) + subarr[i-1];
        }
    }

    int a = 9;
    while(!(N/subarr[a])) {
        a--;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int a = init();

    for (int i=a;i>=0;i--) {
        int div = N / subarr[i];

        if (i != 0 && div == 0) {
            ans[0] -= subarr[i];
        }

        if (i == 0) {
            div++;
        }
        
        for (int j=0;j<div;j++) {
            if (j != 0) ans[j] += subarr[i];
            for (int k=0;k<10;k++) {
                ans[k] += DP[i][1];
            }
        }

        for (int j=0;j<10;j++) {
            if (visit[j]) ans[j] += visit[j] * div * subarr[i];
        }

        visit[div]++;
        N -= div * subarr[i];
    }

    for (int i=0;i<10;i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
