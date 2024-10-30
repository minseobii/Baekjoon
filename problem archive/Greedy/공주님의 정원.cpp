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
int N,ans;
vector<pair<int,int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.push_back({a*100+b,c*100+d});
    }
    sort(v.begin(),v.end());

    int end = 301;
    int Max = 0;
    for (pair<int,int> x : v) {
        if (end < x.first) {
            if (Max == 0 || Max < x.first) {
                cout << 0 << '\n';
                return 0;
            }
            end = Max;
            Max = 0;
            ans++;
            if (end >= 1200) {
                cout << ans << '\n';
                return 0;
            }
        } 
        Max = max(Max, x.second);    
    }

    if (Max >= 1200) ans++;
    else ans = 0;
    
    cout << ans << '\n';
    return 0;
}
