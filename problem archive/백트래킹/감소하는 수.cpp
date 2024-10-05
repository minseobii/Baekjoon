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
int N,cnt;
long long ans = -1;

void bt(long long sum, int level) {
    if (level == 0) {
        if (cnt == N) {
            ans = sum;
        }
        cnt++;
        return;
    }
    int last = sum % 10;
    if (sum == 0) last = 10;
    for (int k=0;k<last;k++) {
        long long nextsum = sum*10+k;
        if (nextsum == 0) continue;
        bt(nextsum,level-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<=10;i++) {
        bt(0,i);
    }
    cout << ans << '\n';
    return 0;
}
