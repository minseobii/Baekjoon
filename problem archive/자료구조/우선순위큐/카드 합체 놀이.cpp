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
int N,M;
long long ans;
priority_queue<long long> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        long long k;
        cin >> k;
        pq.push(-k);
    }

    for (int i=0;i<M;i++) {
        long long a = -pq.top();
        pq.pop();
        long long b = -pq.top();
        pq.pop();

        pq.push(-(a+b));
        pq.push(-(a+b));
    }

    while(!pq.empty()) {
        ans += -pq.top();
        pq.pop();
    }

    cout << ans << '\n';
    return 0;
}
