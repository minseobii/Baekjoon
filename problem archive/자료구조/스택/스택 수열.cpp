#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
bool ans = true;

vector<bool> v;
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int num = 1;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;

        if (num <= k) {
            while(num <= k) {
                st.push(num);
                v.push_back(true);
                num++;
            }   
            st.pop();
            v.push_back(false);
        }

        else {
            if (st.top() != k) ans = false;
            else {
                st.pop();
                v.push_back(false);
            }
        }
    }
    
    if (ans == false) cout << "NO" << '\n';
    else {
        for (int i=0;i<v.size();i++) {
            if (v[i]) cout << '+' << '\n';
            else cout << '-' << '\n';
        }
    }
    return 0;
}
