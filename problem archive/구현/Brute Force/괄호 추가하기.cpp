#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;
int N;
int ans = INT_MIN;
string s;

void DFS(int idx, int sum) {
    char op;
    if (idx == 0) op = '+';
    else op = s[idx-1];

    if (idx >= N) {
        ans = max(ans, sum);
        return;
    }

    if (op == '+') DFS(idx+2, sum+(s[idx]-'0'));
    else if (op == '-') DFS(idx+2, sum-(s[idx]-'0'));
    else if (op == '*') DFS(idx+2, sum*(s[idx]-'0'));

    if (idx+2 < N) {
        int temp;
        if (s[idx+1] == '+') temp = (s[idx] -'0') + (s[idx+2] -'0');
        else if (s[idx+1] == '-') temp = (s[idx] -'0') - (s[idx+2] -'0');
        else if (s[idx+1] == '*') temp = (s[idx] -'0') * (s[idx+2] -'0');

        if (op == '+') DFS(idx+4, sum+temp);
        else if (op == '-') DFS(idx+4, sum-temp);
        else if (op == '*') DFS(idx+4, sum*temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> s;

    DFS(0,0);

    cout << ans << '\n';
    return 0;
}
