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
int N,M,K,ans;
bool arr[50][50];
int numcount[50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        int num = 0;
        for (int j=0;j<M;j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
            if (arr[i][j] == 0) num++;
        }
        numcount[i] = num;
    }
    cin >> K;

    for (int i=0;i<N;i++) {
        int remain = K - numcount[i];
        if (remain < 0 || remain % 2) continue;

        int count = 1;
        for (int j=0;j<N;j++) {
            if (i == j) {
                break;
            }
            bool find = true;
            for (int k=0;k<M;k++) {
                if (arr[i][k] != arr[j][k]) {
                    find = false;
                    break;
                }
            }
            if (find) count++;
        }
        ans = max(ans, count);
    }

    cout << ans << '\n';
    return 0;
}
