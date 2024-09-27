#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
priority_queue<int> pos;
priority_queue<int> neg;
int zero = 0;
long long ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;
        if (k > 0) pos.push(k);
        else if (k < 0) neg.push(-k);
        else zero++;
    }

    while(!pos.empty()) {
        int x = pos.top();
        pos.pop();
        if (pos.empty()) {
            ans += x;
            break;
        }
        int y = pos.top();
        pos.pop();

        if (x != 1 && y != 1) {
            ans += x*y;
        }
        else ans += x+y;
    }

    while(!neg.empty()) {
        int x = neg.top();
        neg.pop();
        if (neg.empty()) {
            if (zero == 0) ans -= x;
            break;
        }
        int y = neg.top();
        neg.pop();
        ans += x*y;
    }

    cout << ans << '\n';
    return 0;
}
