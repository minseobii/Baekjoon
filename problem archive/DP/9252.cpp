#include <iostream>
#include <stack>
using namespace std;
string A,B;
int lenA,lenB,ans;
int DP[1005][1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    int lenA = A.length();
    int lenB = B.length();

    for (int i=1;i<=lenA;i++) {
        for (int j=1;j<=lenB;j++) {
            int temp = max(DP[i-1][j], DP[i][j-1]);
            if (A[i-1] == B[j-1]) {
                temp = max(temp, DP[i-1][j-1]+1);
            }
            DP[i][j] = temp;
        }
    }

    ans = DP[lenA][lenB];
    stack<char> s;

    cout << DP[lenA][lenB] << '\n';
    while(ans) {
        if (DP[lenA][lenB] == DP[lenA-1][lenB]) {
            lenA--;
            continue;
        }
        if (DP[lenA][lenB] == DP[lenA][lenB-1]) {
            lenB--;
            continue;
        }
        if (DP[lenA][lenB] == DP[lenA-1][lenB-1]+1) {
            s.push(A[lenA-1]);
            ans--;
            lenA--;
            lenB--;
        }
    }
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';
    return 0;
}
