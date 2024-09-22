#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
long long ans;
stack<pair<int,int>> st;

// void print() {
//     stack<pair<int,int>> temp;
//     while(!st.empty()) {
//         cout << st.top().first << ' ' << st.top().second << '\n';
//         temp.push(st.top());
//         st.pop();
//     }
//     while(!temp.empty()) {
//         st.push(temp.top());
//         temp.pop();
//     }
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;

        if (st.empty()) {
            st.push({k,1});
            continue;
        }
        
        if (st.top().first == k) {
            ans += st.top().second++;
            if (st.size() > 1) ans += 1;
        }
        else if (st.top().first > k) {
            ans += 1;
            st.push({k,1});
        }
        else if (st.top().first < k) {
            while(!st.empty()) {
                if (st.top().first == k) {
                    ans += st.top().second++;
                    if (st.size() > 1) ans += 1;
                    break;
                }
                else if (st.top().first > k) {
                    ans += 1;
                    st.push({k,1});
                    break;
                }
                else if (st.top().first < k) {
                    ans += st.top().second;
                    st.pop();
                }
            }

            if (st.empty()) st.push({k,1});
        }
        // print();
        // cout << ans << '\n';
        // cout << '\n';
    }

    cout << ans << '\n';
    return 0;
}
