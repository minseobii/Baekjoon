#include <iostream>
using namespace std;
int N;
int arr[1000];
int DP[1000][2];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    for (int i=0;i<N;i++) {
        int tempinc = 1;
        int tempdec = 1;
        for (int j=0;j<i;j++) {
            if (arr[j] < arr[i]) {
                tempinc = max(tempinc, DP[j][0]+1);
            }
            else if (arr[j] > arr[i]) {
                tempdec = max(tempdec, DP[j][1]+1);
                tempdec = max(tempdec, DP[j][0]+1);
            }
        }
        ans = max(tempinc, ans);
        ans = max(tempdec, ans);
        DP[i][0] = tempinc;
        DP[i][1] = tempdec;
    }

    cout << ans << endl;
    return 0;
}
