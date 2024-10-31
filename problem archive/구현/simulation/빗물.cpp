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
int H,W,ans,A[500];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> H >> W;

    for (int i=0;i<W;i++) {
        cin >> A[i];
    }

    for (int i=1;i<=H;i++) {
        bool rain = false;
        int sum = 0;
        for (int j=0;j<W;j++) {
            if (i <= A[j]) {
                rain = true;
                ans += sum;
                sum = 0;
            }
            else if (rain) {
                sum++;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}
