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
int N,S1,S2;
long long ans, arr[1000000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }   
    cin >> S1 >> S2;
    for (int i=0;i<N;i++) {
        arr[i] -= S1;
        ans += 1;

        if (arr[i] > 0) {
            if (arr[i] % S2) ans += 1;
            ans += arr[i] / S2;
        }
    }
    cout << ans << '\n';
    return 0;
}
