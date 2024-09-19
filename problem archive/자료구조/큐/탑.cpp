#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
int arr[500001];
int ans[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    priority_queue<pair<int,int>> q;

    for (int i=N;i>=1;i--) {
        while (!q.empty() && -q.top().first < arr[i]) {
            ans[q.top().second] = i;
            q.pop();
        }
        q.push({-arr[i],i});
    }

    for (int i=1;i<=N;i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
