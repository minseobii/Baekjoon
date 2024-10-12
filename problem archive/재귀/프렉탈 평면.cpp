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
int s, N, K, L, R1, R2, C1, C2, ans[50][50];

bool cal(int r, int c, int level) {
    if (level == 0) return false;
    int l1 = ((N-K)/2)*level;
    int l2 = ((N+K)/2)*level;
    if (r >= l1 && c >= l1 && r < l2 && c < l2) return true;

    if (cal(r%level,c%level,level/N)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;

    L = 1;
    for (int i=1;i<s;i++) {
        L *= N;
    }

    for (int i=0;i<=R2-R1;i++) {
        for (int j=0;j<=C2-C1;j++) {
            if (cal(R1+i,C1+j,L)) cout << 1;
            else cout << 0;
        }
        cout << '\n';
    }
    return 0;
}
