#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M;
bool arr[201][201];
bool ans[201][201];
int D[1000];

void mul(bool A[][201], bool B[][201]) {
    int temp[201][201] = {0,};
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            for (int k=1;k<=N;k++) {
                temp[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (temp[i][j]) A[i][j] = true;
            else A[i][j] = false;
        }
    }
}

void cal(int n) {
    while(n > 0) {
        if (n%2) {
            mul(ans,arr);
        }
        mul(arr,arr);
        n /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int k;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            if (i == j) {
                cin >> k;
                arr[i][j] = true;
                ans[i][j] = true;
                continue;
            }
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<M;i++) {
       cin >> D[i];
    }
    cal(N);

    for (int i=0;i<M-1;i++) {
        if (ans[D[i]][D[i+1]] == false) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    return 0;
}
