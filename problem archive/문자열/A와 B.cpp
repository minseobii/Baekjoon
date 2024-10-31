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
string S,T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S >> T;

    bool forward = true;
    int left = 0;
    int right = T.length()-1;
    for (int i=0;i<T.length()-S.length();i++) {
        if (forward) {
            if (T[right] == 'A') right--;
            else {
                right--;
                forward = false;
            }
        }
        else {
            if (T[left] == 'A') left++;
            else {
                left++;
                forward = true;
            }
        }
    }

    int idx = 0;
    if (forward) {
        for (int i=left;i<=right;i++) {
            if (S[idx] != T[i]) {
                cout << 0 << '\n';
                return 0;
            }
            idx++;
        }
    }
    else {
        for (int i=right;i>=left;i--) {
            if (S[idx] != T[i]) {
                cout << 0 << '\n';
                return 0;
            }
            idx++;
        }
    }
    cout << 1 << '\n';
    return 0;
}
