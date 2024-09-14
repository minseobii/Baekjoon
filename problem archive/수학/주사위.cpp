#include <iostream>
#include <algorithm>
using namespace std;
long long N;
long long ans;
long long subarr[8][3] = {{0,1,2},{0,1,3},{0,3,4},{0,2,4},{1,2,5},{1,3,5},{2,4,5},{3,4,5}};
long long arr[6];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<6;i++) {
        cin >> arr[i];
    }
    
    long long side3 = 1000;
    long long side2 = 1000;

    for (int i=0;i<6;i++) {
        for (int j=0;j<6;j++) {
            if (i+j==5 || i==j) continue;
            side2 = min(side2,arr[i]+arr[j]);
        }
    }

    for (int i=0;i<8;i++) {
        side3 = min(side3, arr[subarr[i][0]]+arr[subarr[i][1]]+arr[subarr[i][2]]);
    }

    sort(arr,arr+6);

    if (N == 1) {
        for (int i=0;i<5;i++) {
            ans += arr[i];
        }
    }
    else {
        ans += 4 * side3;
        ans += (8*N-12) * side2;
        ans += (N-2) * (5*N-6) * arr[0];
    }

    cout << ans << endl;
    return 0;
}
