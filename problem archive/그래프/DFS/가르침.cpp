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
int N,K,ans;
string arr[50];
bool alpha[26];

void dfs(int a, int b) {
    if (b == K-5) {
        int count = 0;
        for (int i=0;i<N;i++) {
            bool find = true;
            for (char c : arr[i]) {
                if (alpha[c - 'a'] == false) find = false;
            }
            if (find) count++;
        }
        ans = max(ans, count);
        return;
    }

    for (int i=a;i<26;i++) {
        if (alpha[i]) continue;
        alpha[i] = true;
        dfs(i+1, b+1);
        alpha[i] = false;
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    alpha[0] = true;
    alpha[13] = true;
    alpha[19] = true;
    alpha[8] = true;
    alpha[2] = true;

    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    dfs(0,0);

    cout << ans << '\n';
    return 0;
}
