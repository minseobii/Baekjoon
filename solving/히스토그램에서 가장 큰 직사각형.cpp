#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
long long ans;
int arr[100000];
stack<int> st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N) {
        int k;
        int n = 0;
        for (int i=0;i<N;i++) {
            cin >> k;

            if (st.empty()) {
                st.push(k);
                ans = max(k,ans);
                n = 1;
            }
            else {
                
            }
        }
        cin >> N;
    }
    cout << ans << '\n';
    return 0;
}
