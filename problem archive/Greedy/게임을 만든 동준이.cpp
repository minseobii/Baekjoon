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
int N,ans,arr[100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int prev = arr[N-1];
    for (int i=N-2;i>=0;i--) {
        while(arr[i] >= prev) {
            ans++;
            arr[i]--;
        }
        prev = arr[i];
    }

    cout << ans << '\n';
    return 0;
}
