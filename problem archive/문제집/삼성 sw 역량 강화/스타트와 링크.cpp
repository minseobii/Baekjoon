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
int N,arr[20][20];
int ans = 100000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    bool subarr[N] = {0,};
    for (int i=0;i<N;i++) {
        if (i < (N/2)) subarr[i] = false;
        else subarr[i] = true;
    }

    do {
        vector<int> team0;
        vector<int> team1;
        int temp0 = 0;
        int temp1 = 0;
        for (int i=0;i<N;i++) {
            if (subarr[i]) team1.push_back(i);
            else team0.push_back(i);
        }

        for (int i : team0) {
            for (int j : team0) {
                if (i >= j) continue;
                temp0 += arr[i][j] + arr[j][i];
            }
        }
        for (int i : team1) {
            for (int j : team1) {
                if (i >= j) continue;
                temp1 += arr[i][j] + arr[j][i];
            }
        }
        ans = min(ans, abs(temp0-temp1));
    } while(next_permutation(subarr,subarr+N));

    cout << ans << '\n';
    return 0;
}
