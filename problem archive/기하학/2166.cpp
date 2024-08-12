#include <iostream>
#include <cmath>
using namespace std;
int N;
double arr[10000][2];
double ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i=0;i<N;i++) {
        if (i == N-1) {
            ans += (arr[i][0] * arr[0][1]) - (arr[i][1] * arr[0][0]);
        }
        else {
            ans += (arr[i][0] * arr[i+1][1]) - (arr[i][1] * arr[i+1][0]);
        }
    }
    cout << fixed;
    cout.precision(1);
    cout << round(abs(ans/2)*10)/10 << endl;
    return 0;
}
