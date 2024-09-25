#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int N;
int arr[100000];
stack<int> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N) {
        long long ans = 0;
        long long ll = 1;
        for (int i=0;i<N;i++) {
            cin >> arr[i];
        }
        
        for (int i=0;i<N;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int width = i;
                int height = arr[st.top()];
                st.pop();

                if (!st.empty()) width = i - st.top() - 1;

                ans = max(ans, ll * width * height);
            }   
            st.push(i);
        }

        while(!st.empty()) {
            int width = N;
            int height = arr[st.top()];
            st.pop();
            if (!st.empty()) width = N - st.top() - 1;
            ans = max(ans, ll * width * height);
        }

        cout << ans << '\n';
        cin >> N;
    }
    return 0;
}
