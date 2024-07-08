#include <iostream>
#include<utility>
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
        int arr[N+1];
        int zeronum[N+1] = {0,};
        int onenum[N+1] = {0,};
        for (int i=0;i<N+1;i++) {
            if (i==0) {
                arr[i] = 0;
                zeronum[i] = 1;
            }
            else if (i==1) {
                arr[i] = 1;
                onenum[i] = 1;
            }
            else {
                arr[i] = arr[i-1] + arr[i-2];
                zeronum[i] = zeronum[i-1] + zeronum[i-2];
                onenum[i] = onenum[i-1] + onenum[i-2];
            }
        }
        cout << zeronum[N] << ' ' << onenum[N] << '\n';
    }
        return 0;
}
