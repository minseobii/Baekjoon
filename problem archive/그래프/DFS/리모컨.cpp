#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M,ans;
bool broken[10];

void DFS(int num, int a) {
    if (a == 7) return;
    for (int i=0;i<10;i++) {
        if (broken[i]) continue;
        ans = min(ans,abs((num*10+i)-N) + a);
        DFS(num*10 + i,a+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int k; cin >> k;
        broken[k] = true;
    }
    ans = abs(N - 100);

    DFS(0,1);

    cout << ans << '\n';
    return 0;
}
