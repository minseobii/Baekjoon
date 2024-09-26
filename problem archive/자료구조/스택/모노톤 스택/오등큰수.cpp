#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
stack<int> st;
pair<int,int> arr[1000000];
int subarr[1000001];
int ans[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;   
    for (int i=0;i<N;i++) {
        cin >> arr[i].first;
        subarr[arr[i].first] += 1;
    }
    for (int i=0;i<N;i++) {
        arr[i].second = subarr[arr[i].first];
    }

    for (int k=0;k<N;k++) {
        while(!st.empty() && arr[st.top()].second < arr[k].second) {
            ans[st.top()] = arr[k].first;
            st.pop();
        }
        st.push(k);
    }

    while(!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }

    for (int i=0;i<N;i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
