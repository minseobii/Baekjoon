#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M,ans;
bool A[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char c;
            cin >> c;
            A[i][j] = c - '0';

            if (A[i][j]) ans = 1;
        }
    }

    for (int k=1;k<min(N,M);k++) {
        for (int i=0;i+k<N;i++) {
            for (int j=0;j+k<M;j++) {
                if (A[i][j] && A[i+1][j] && A[i][j+1] && A[i+1][j+1]) {
                    ans = (k+1) * (k+1);
                    continue;
                }
                A[i][j] = false;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
