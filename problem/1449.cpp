#include <iostream>
#include <algorithm>
using namespace std;
int N,L;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    int arr[N]={0,};
    for (int i=0;i<N;i++) {
        cin >> arr[i]; 
    }
    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        if (arr[i] != 0) {
            int right = min(i+L,N);
            int num = arr[i];
            for (int j=i;j<right;j++) {
                if (arr[j] != 0 && arr[j] < num+L) {
                    arr[j] = 0;
                }
            }
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
