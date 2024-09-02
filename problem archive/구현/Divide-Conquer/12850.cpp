#include <iostream>
#define MOD 1000000007
using namespace std;
int N;
long long X[8][8];
long long ans[8][8];
long long sub[24][2] = {{0,1},{0,2},{1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,5},{4,6},{5,7},{6,7},
                        {1,0},{2,0},{2,1},{3,1},{3,2},{4,2},{4,3},{5,3},{5,4},{6,4},{7,5},{7,6}};

void cal(long long A[][8], long long B[][8]) {
    long long temp[8][8] = {0,};
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            for (int k=0;k<8;k++) {
                temp[i][j] += (A[i][k] * B[k][j]) % MOD;
            }
        }
    }

    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            A[i][j] = temp[i][j] % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<24;i++) {
        X[sub[i][0]][sub[i][1]] = 1;
    }
    for (int i=0;i<8;i++) {
        for (int j=0;j<8;j++) {
            if (i == j) ans[i][j] = 1;
        }
    }

    while(N>0) {
        if (N%2) cal(ans,X);
        cal(X,X);
        N /= 2;
    }

    cout << ans[0][0] << endl;
    return 0;
}
