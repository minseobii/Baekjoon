#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;
string s;
int ans;
stack<int> st;
map<char,int> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;

    m['('] = -1;
    m[')'] = -2;
    m['['] = -3;
    m[']'] = -4;

    for (int i=0;i<s.length();i++) {
        int k = m[s[i]];
        if (st.empty() || k == -1 || k == -3) {
            st.push(k);
            continue;
        }

        int sum = 0;
        while(!st.empty() && st.top() > 0) {
            sum += st.top();
            st.pop();
        }
        if (sum == 0) sum = 1;

        if (st.empty() || st.top() != k+1) {
            cout << 0 << '\n';
            return 0;
        }

        if (st.top() == -1) sum *= 2;
        else if (st.top() == -3) sum *= 3;

        st.pop();
        while(!st.empty() && st.top() > 0) {
            sum += st.top();
            st.pop();
        }
        st.push(sum);
    }
    
    if (st.top() > 0 && st.size() == 1) cout << st.top() << '\n';
    else cout << 0 << '\n';
    return 0;
}
