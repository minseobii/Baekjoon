#include <iostream>
using namespace std;
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        int arr[N+1] = {0,};

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


            if (i-1 > 0) {
                arr[i] += arr[i-1];
            }
            if (i-2 > 0) {
                arr[i] += arr[i-2];
            }
            if (i-3 > 0) {
                arr[i] += arr[i-3];
            }
        }
        cout << arr[N] << '\n';
    }

    return 0;
}
