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
string str = "bdefghjklmopqrsuvuxyz";
string arr[50];
bool alpha[26];

void dfs(int a, int b) {
    if (b == K) {
        int count = 0;
        for (int i=0;i<N;i++) {
            bool find = true;
            for (char c : arr[i]) {
                if (alpha[c] == false) find = false;
            }
            if (find) count++;
        }
        ans = max(ans, count);
        return;
    }

    for (int i=a;i<str.length();i++) {
        if (alpha[str[i]]) continue;
        alpha[str[i]] = true;
        dfs(a+1, b+1);
        alpha[str[i]] = false;
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
    alpha['a'] = true;
    alpha['n'] = true;
    alpha['t'] = true;
    alpha['i'] = true;
    alpha['c'] = true;

    dfs(0,0);

    cout << ans << '\n';
    return 0;
}
