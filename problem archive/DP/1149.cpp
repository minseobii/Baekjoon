#include <iostream>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N][3] = {0,};
    for (int i=0;i<N;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if (i==0) {
            arr[i][0] = a;
            arr[i][1] = b;
            arr[i][2] = c;
        }
        else {
            arr[i][0] = min(arr[i-1][1],arr[i-1][2]) + a;
            arr[i][1] = min(arr[i-1][0],arr[i-1][2]) + b;
            arr[i][2] = min(arr[i-1][0],arr[i-1][1]) + c;
        }
    }
    cout << min(min(arr[N-1][0],arr[N-1][1]), arr[N-1][2]) << endl;
    return 0;
}
