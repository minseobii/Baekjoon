#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000003
using namespace std;
int N,S,E,T;
long long arr[50][50];
long long ans[50][50];
char K;

void cal_mul(long long A[][50], long long B[][50]) {
    long long temp[50][50] = {0,};
    for (int i=0;i<5*N;i++) {
        for (int j=0;j<5*N;j++) {
            for (int k=0;k<5*N;k++) {
                temp[i][j] = (temp[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
            }
        }
    }

    for (int i=0;i<5*N;i++) {
        for (int j=0;j<5*N;j++) {
            A[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S >> E >> T;
    for (int i=0;i<N;i++) {
        for (int j=4;j>0;j--) {
            arr[5*i+j][5*i+j-1] = 1;
        }
    }
    for (int i=0;i<5*N;i++) {
        for (int j=0;j<5*N;j++) {
            if (i == j) ans[i][j] = 1;
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i == j) ans[i][j] = 1;
            cin >> K;
            int input = K-'0';
            if (input == 0) continue;
            arr[5*i][5*j+input-1] = 1;
        }
    }

    while(T>0) {
        if (T%2) cal_mul(ans, arr);
        cal_mul(arr, arr);
        T /= 2;
    }

    cout << ans[5*(S-1)][5*(E-1)] << '\n';

    return 0;
}
