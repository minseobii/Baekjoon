#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MOD 1000000007
using namespace std;
int T,N,D;
long long bloodmap[100][20][20];
long long cycle[20][20];
long long ans[20][20];

void mul(long long A[][20], long long B[][20]) {
    long long temp[20][20] = {0,};
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            for (int k=0;k<N;k++) {
                temp[i][j] = (temp[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            A[i][j] = temp[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T >> N >> D;
    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            if (i == j) {
                ans[i][j] = 1;
                cycle[i][j] = 1;
            }
        }
    }
    
    for (int t=0;t<T;t++) {
        int m,a,b,c;
        cin >> m;
        for (int i=0;i<m;i++) {
            cin >> a >> b >> c;
            bloodmap[t][a-1][b-1] = c;
        }

        mul(cycle, bloodmap[t]);
    }

    int x = D / T;
    int a = D % T;
    while(x > 0) {
        if (x%2) mul(ans, cycle);
        mul(cycle, cycle);
        x /= 2;
    }
    for (int i=0;i<a;i++) {
        mul(ans, bloodmap[i]);
    }
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
