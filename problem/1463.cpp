#include <iostream>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N+1] = {0,};

    for (int i=1;i<N+1;i++) {
        int div2 = i%2;
        int div3 = i%3;

        if (i==1) {
            arr[1] = 0;
        }
        else if (!div2 && div3) {
            arr[i] = min(arr[i/2], arr[i-1]) + 1;
        }
        else if (!div3 && div2) {
            arr[i] = min(arr[i/3], arr[i-1]) + 1;
        }
        else if (!div3 && !div2) {
            int temp = min(arr[i/2],arr[i/3]);
            arr[i] = min(temp,arr[i-1]) + 1;
        }
        else {
            arr[i] = arr[i-1]+1;
        }
    }
    cout << arr[N] << '\n';
    return 0;
}
