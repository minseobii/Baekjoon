#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,C,ans;
int arr[200000];

bool fn(int x) {
    int count = 1;
    int num = arr[0];
    for (int i=1;i<N;i++) {
        if (arr[i] - num >= x) {
            count++;
            num = arr[i];
        }
    }

    if (count >= C) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    int left = 0;
    int right = 1000000000;
    while(left <= right) {
        int mid = (left + right) / 2;
        if (fn(mid) == true) {
            ans = max(ans, mid);
            left = mid+1;
        }
        else right = mid-1;
    }

    cout << ans << '\n';
    return 0;
}
