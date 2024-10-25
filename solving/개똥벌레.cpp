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
int N,H,even[100001],odd[100000];
pair<int,int> ans = {200001,0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> H;
    for (int i=0;i<N;i++) {
        if (i % 2 == 0) {
            cin >> even[i/2];
        }
        else {
            cin >> odd[i/2];
        }
    }
    sort(even,even+N/2);
    sort(odd,odd+N/2);

    for (int i=2;i<=H;i++) {
        int up = lower_bound(even,even+N/2,i) - even;
        int down = lower_bound(odd,odd+N/2,H-i+1) - odd;
        int temp = (N/2-up) + (N/2-down);
        if (ans.first == temp) ans.second += 1;
        else if (ans.first > temp) ans = {temp, 1};
    }

    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}
