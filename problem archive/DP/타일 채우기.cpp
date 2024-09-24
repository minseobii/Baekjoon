#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans;
int arr[31];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    arr[0] = 1;
    if (N % 2) cout << 0 << '\n';
    else {
        for (int i=2;i<=N;i+=2) {
            if (i == 2) {
                arr[i] = 3;
                continue;
            }


            arr[i] += arr[i-2] * 3;

            for (int j=0;j<=i-4;j+=2) {
                arr[i] += arr[j] * 2;
            }
        }
        cout << arr[N] << '\n';
    }
    return 0;
}
