#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int K,N;
long long ans, arr[10000];

bool solve(long long a) {
    if (a == 0) return false;

    int temp = 0;
    for (int i=0;i<K;i++) {
        temp += (arr[i] / a);
    }

    if (temp >= N) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K >> N;

    for (int i=0;i<K;i++) {
        cin >> arr[i];
    }

    long long left = 0;
    long long right = (1 << 31) - 1;
    long long mid;
    while(left <= right) {
        mid = (left + right) / 2;
        if (solve(mid) == true) {
            ans = max(ans, mid);
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
