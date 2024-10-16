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
string s;
int N,set0, set1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    N = s.length();
    char num = '2';
    for (int i=0;i<N;i++) {
        if (num == '2') {
            num = s[i];
            if (num == '0') set0++;
            else set1++;
            continue;
        }
        if (num == s[i]) continue;
        else {
            num = s[i];
            if (num == '0') set0++;
            else set1++;
        }
    }

    if (set0+set1 == 1) cout << 0 << '\n';
    else cout << min(set0, set1) << '\n';
    return 0;
}
