#include <iostream>
using namespace std;
string N,M;
int LCS[1005][1005];
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N.length();i++) {
        for (int j=0;j<M.length();j++) {
            if (N[i] == M[j]) {
                LCS[i+1][j+1] = LCS[i][j] + 1;
                ans = max(ans , LCS[i+1][j+1]);
            }
            else {
                LCS[i+1][j+1] = max(LCS[i+1][j], LCS[i][j+1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
