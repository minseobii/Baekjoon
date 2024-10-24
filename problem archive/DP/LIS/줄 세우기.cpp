#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans,arr[200],A[201];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int count = 1;
    for (int i=0;i<N;i++) {
        int u = upper_bound(A,A+count,arr[i]) - A;
        if (u == count) count++;
        A[u] = arr[i];
    }

    cout << N - count + 1 << '\n';
    return 0;
}
