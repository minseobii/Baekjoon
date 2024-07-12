#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N];
    int subarr[N];
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    for (int i=0;i<N;i++) {
        cin >> subarr[i];
    }

    sort(arr,arr+N);
    sort(subarr,subarr+N);

    for (int i=0;i<N;i++) {
        ans += arr[i] * subarr[N-i-1];
    }

    cout << ans << endl;
    return 0;
}
