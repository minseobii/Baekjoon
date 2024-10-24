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
int N,K,ans,arr[10001];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    ans = arr[N-1] - arr[0];

    for (int i=0;i<N-1;i++) {
        v.push_back(arr[i+1] - arr[i]);
    }
    sort(v.begin(),v.end(),greater<>());
    for (int i=0;i<K-1;i++) {
        if (i < v.size()) ans -= v[i];
    }

    cout << ans << '\n';
    return 0;
}
