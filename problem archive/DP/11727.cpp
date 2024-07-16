#include <iostream>
using namespace std;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int arr[n+1];
    for (int i=1;i<n+1;i++) {
        if (i==1) {
            arr[i] = 1;
        }
        else if (i==2) {
            arr[i] = 3;
        }
        else {
            arr[i] = (2 * arr[i-2] + arr[i-1]) % 10007;
        }
    }
    cout << arr[n] % 10007 << '\n';
    return 0;
}
