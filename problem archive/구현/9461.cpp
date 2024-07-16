#include <iostream>
using namespace std;
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        long long arr[N+1];

        for (int i=1;i<N+1;i++) {
            if (i==1) {
                arr[i] = 1;
            }
            else if (i==2) {
                arr[i] = 1;
            }
            else if (i==3) {
                arr[i] = 1;
            }
            else if (i==4) {
                arr[i] = 2;
            }
            else if (i==5) {
                arr[i] = 2;
            }
            else if (i==6) {
                arr[i] = 3;
            }
            else {
                arr[i] = arr[i-1] + arr[i-5];
            }
        }
        cout << arr[N] << '\n';
    }
    return 0;
}
