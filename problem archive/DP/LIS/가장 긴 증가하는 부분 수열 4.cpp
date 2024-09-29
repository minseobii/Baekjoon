#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans;
int n = 1;
int arr[1001];
int A[1001];
int B[1001];
int bt[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        int k;
        cin >> k;
        arr[i] = k;

        int l = lower_bound(A,A+n,k) - A;
        if (l == n) n++;
        bt[i] = B[l-1];
        B[l] = i;
        A[l] = k;
    }
    cout << n-1 << '\n';

    stack<int> st;
    int idx = B[n-1];
    do {
        st.push(arr[idx]);
        idx = bt[idx];
    } while(arr[idx]);

    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';

    return 0;
}
