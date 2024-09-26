#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,K;
stack<int> st;
stack<int> ans;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    cin >> s;
    for (int i=0;i<N;i++) {
        int k = s[i] - '0';
        while(!st.empty() && st.top() < k && K > 0) {
            st.pop();
            K--;
        }   
        st.push(k);
    }

    while(K > 0) {
        st.pop();
        K--;
    }

    while(!st.empty()) {
        ans.push(st.top());
        st.pop();
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    return 0;
}
