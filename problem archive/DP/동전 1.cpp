#include <iostream>
using namespace std;
int n,k,ans;
int arr[100];
int DP[10001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    DP[0] = 1;

    for (int i=0;i<n;i++) {
        for (int j=1;j<=k;j++) {
            if (j-arr[i] >= 0) {
                DP[j] += DP[j-arr[i]];
            }
        }
    } 

    cout << DP[k] << endl;
    return 0;
}
