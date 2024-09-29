#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M;
long long ans;

int sum[1000001];
int mod[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    mod[0] = 1;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;
        sum[i+1] = (sum[i] + k) % M;
        if (mod[sum[i+1]]) ans += mod[sum[i+1]];

        mod[sum[i+1]] += 1;
    }
    cout << ans << '\n';
    return 0;
}
