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
int T;

int ispal(string s, int l, int r, bool type) {
    while(l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
            continue;
        }
        else {
            if (type == true) {
                if (ispal(s,l+1,r,false) == 1 || ispal(s,l,r-1,false) == 1) return 1;
                else return 2;
            }
            else return 2;
        }
    }

    if (type == true) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        cout << ispal(s,0,s.length()-1,true) << '\n';
    }
    return 0;
}
