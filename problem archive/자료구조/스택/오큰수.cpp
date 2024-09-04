#include <iostream>
#include <stack>
using namespace std;
int N;
stack<pair<int,int>> st;
int ans[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;
        while(!st.empty()) {
            if (st.top().first < k) {
                ans[st.top().second] = k;
                st.pop();
            }
            else break;
        }

        st.push({k,i});
    }

    while(!st.empty()) {
        ans[st.top().second] = -1;
        st.pop();
    }

    for (int i=0;i<N;i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
