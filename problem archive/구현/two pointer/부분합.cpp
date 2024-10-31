#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 100001
using namespace std;
int N,S,A[MAX];
int ans = MAX;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;

    for (int i=1;i<=N;i++) {
        int k;
        cin >> k;
        A[i] = A[i-1] + k;
    }

    int left = 0;
    int right = 1;
    int sum;
    while(right <= N) {
        sum = A[right] - A[left];
        if (sum >= S) {
            ans = min(ans, right - left);
            left++;
        }
        else {
            right++;
        }
    }
    
    if (ans == MAX) ans = 0;
    cout << ans << '\n';
    return 0;
}
