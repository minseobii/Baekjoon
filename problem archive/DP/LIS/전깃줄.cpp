#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
int idx = 1;
int arr[501];
int A[501];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        arr[a] = b;
    }

    for (int i=1;i<=500;i++) {
        if (arr[i] == 0) continue;
        int u = upper_bound(A,A+idx,arr[i]) - A;
        if (u == idx) idx++;
        A[u] = arr[i];
    }

    cout << N - idx + 1 << '\n';
    return 0;
}
