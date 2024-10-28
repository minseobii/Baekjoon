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
int k,N;
long long num, ans;
stack<int> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> k;
        while(!st.empty() && st.top() <= k) {
            st.pop();
            ans += --num;
        }
        st.push(k);
        num++;
    }

    while(!st.empty()) {
        st.pop();
        ans += --num;
    }

    cout << ans << '\n';
    return 0;
}
