#include <iostream>
using namespace std;
int N, K;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    int arr[N];

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    for (int i=N-1;i>=0;i--) {
        while (K >= arr[i]) {
            K -= arr[i];
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
