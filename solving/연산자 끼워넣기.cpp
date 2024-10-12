#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1000000001
using namespace std;
int N,Max,Min,arr[100],oper[4];

void dfs(int sum, int cnt) {
    if (cnt == N-1) {
        Max = max(Max, sum);
        Min = min(Min, sum);
        return;
    }

    if (oper[0]) {
        oper[0]--;
        dfs(sum+arr[cnt+1],cnt+1);
        oper[0]++;
    }
    if (oper[1]) {
        oper[1]--;
        dfs(sum-arr[cnt+1],cnt+1);
        oper[1]++;  
    }
    if (oper[2]) {
        oper[2]--;
        dfs(sum*arr[cnt+1],cnt+1);
        oper[2]++;
    }
    if (oper[3]) {
        oper[3]--;
        dfs(sum/arr[cnt+1],cnt+1);
        oper[3]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    Max = -INF;
    Min = INF;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    for (int i=0;i<4;i++) {
        cin >> oper[i];
    }

    dfs(arr[0],0);

    cout << Max << '\n';
    cout << Min << '\n';
    return 0;
}
