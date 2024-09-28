#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int T,K;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> K;
        priority_queue<long long> pq;
        long long k;
        long long ans = 0;

        for (int i=0;i<K;i++) {
            cin >> k;
            pq.push(-k);
        }

        while(1) {
            long long x = -pq.top();
            pq.pop();
            if (pq.empty()) break;
            long long y = -pq.top();
            pq.pop();

            ans += x+y;
            pq.push(-(x+y));
        }
        cout << ans << '\n';
    }
    return 0;
}
