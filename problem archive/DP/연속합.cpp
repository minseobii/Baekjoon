#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
int ans = -1001;
int DP[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;

        if (i == 0) DP[i] = k;
        else {
            DP[i] = max(DP[i-1]+k,k);
        }
        ans = max(DP[i],ans);
    }

    cout << ans << '\n';
    return 0;
}
