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
int N,ans;
pair<int,int> arr[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+N);

    int right = -INF;
    for (int i=0;i<N;i++) {
        if (right <= arr[i].first) {
            ans += (arr[i].second - arr[i].first);
            right = arr[i].second;
        }
        else if (arr[i].first < right && right < arr[i].second) {
            ans += arr[i].second - right;
            right = arr[i].second;
        }
    }

    cout << ans << '\n';
    return 0;
}
