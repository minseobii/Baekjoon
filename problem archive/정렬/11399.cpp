#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans;
int main() {
    cin >> N;
    int arr[N];
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    for (int i=1;i<N;i++) {
        arr[i] = arr[i-1] + arr[i];
        ans += arr[i];
    }
    cout << ans+arr[0] << endl;
    return 0;
}
