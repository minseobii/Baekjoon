#include <iostream>
using namespace std;
int N;
int ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int arr[N+1] = {0,};
    
    for (int i=1;i<N+1;i++) {
        if (i == 1) {
            arr[1] = 1;
        }
        else if (i == 2) {
            arr[2] = 2;
        }
        else if (i == 3) {
            arr[3] = 3;
        }
        else {
            arr[i] = (arr[i-1] + arr[i-2]) % 10007;
        }
    }

    cout << arr[N] % 10007 << endl;
    return 0;
}
