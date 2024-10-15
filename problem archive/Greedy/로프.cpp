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
int N,ans,arr[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N,greater<>());

    for (int i=0;i<N;i++) {
        ans = max(ans, arr[i]*(i+1));
    }

    cout << ans << '\n';
    return 0;
}
