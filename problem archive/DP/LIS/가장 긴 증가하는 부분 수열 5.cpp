#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[1000001];
int LIS[1000001];
int LIS_IDX[1000001];
int ans[1000001];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int count = 1;
    LIS[0] = -1000000001;
    for (int i=0;i<N;i++) {
        int k;
        cin >> k;
        arr[i] = k;

        int u = upper_bound(LIS,LIS+count,k) - LIS;
        int l = lower_bound(LIS,LIS+count,k) - LIS;

        if (u != l) continue;

        LIS[u] = k;
        LIS_IDX[u] = i;

        if (u == 1) ans[i] = -1;
        else ans[i] = LIS_IDX[u-1];

        if (count == u) count++; 
    }

    cout << count-1 << '\n';

    int num = LIS_IDX[count-1];
    while(ans[num] != -1) {
        v.push_back(arr[num]);
        num = ans[num];
    }
    v.push_back(arr[num]);
    
    
    for (int i=v.size()-1;i>=0;i--) {
        cout << v[i] << ' ';
    }
    cout << '\n';

    return 0;
}
