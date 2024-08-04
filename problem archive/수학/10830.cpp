#include <iostream>
using namespace std;
int N;
long long B;
int arr[5][5];
int solve[100][5][5];

int ans[5][5];

int sqrt2(long long k) {
    int a=0;
    while(k != 0) {
        k /= 2;
        a++;
    }
    return a-1;
}

void cal(long long k) {
    int temp[5][5] = {0,};
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            for (int l=0;l<N;l++) {
                temp[i][j] += ((ans[i][l] % 1000) * (solve[sqrt2(k)][l][j] % 1000)) % 1000;
                temp[i][j] %= 1000;
            }
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            ans[i][j] = temp[i][j];
        }
    }
}

void divide(long long n) {
    if (B % 2 == 1) {
        B-=1;
        cal(1);
    }
    while (B != 0) {
        if (n <= B) {
            cal(n);
            B -= n;
        }
        n /= 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> B;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (i == j) {
                ans[i][j] = 1;
            }
            cin >> arr[i][j];
            solve[0][i][j] = arr[i][j];
        }
    }
    long long num=2;
    int idx=1;
    while(num <= B) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                for (int k=0;k<N;k++) {
                    solve[idx][i][j] += ((solve[idx-1][i][k] % 1000) * (solve[idx-1][k][j] % 1000)) % 1000;
                    solve[idx][i][j] %= 1000;
                }
            }
        }
        num *= 2;
        idx++;
    }
    divide(num/2);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}