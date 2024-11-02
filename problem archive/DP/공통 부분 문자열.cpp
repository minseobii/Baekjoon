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
int ans;
int arr[4005][4005];
string A,B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;

    for (int i=1;i<=A.length();i++) {
        for (int j=1;j<=B.length();j++) {
            char a = A[i-1];
            char b = B[j-1];
            if (a == b) arr[i][j] = arr[i-1][j-1] + 1;
            ans = max(ans, arr[i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
