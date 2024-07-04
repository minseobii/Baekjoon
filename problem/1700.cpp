#include <iostream>
using namespace std;
int N,K;
int ans=0;
int main() {
    cin >> N >> K;
    int arr[N] = {0,};
    int inputarr[K];
    for (int i=0;i<K;i++) {
        cin >> inputarr[i];
    }

    for (int i=0;i<K;i++) {
        int find=0;
        for (int j=0;j<N;j++) {
            if (arr[j] == 0) {
                arr[j] = inputarr[i];
                find = 1;
                break;
            }
            else if (arr[j] == inputarr[i]) {
                find = 1;
                break;  
            }
        }
        
        if (find == 0) {
            int disarr[N] = {0,};
            int maxnum = 0;
            int changeidx = 0;
            int count = 0;
            for (int k=i+1;k<K;k++) {
                if (count == N) {
                    break;
                }
                for (int f=0;f<N;f++) {
                    if (inputarr[k] == arr[f]) {
                        if (disarr[f] == 0) {
                            disarr[f] = k;
                            count++;
                            if (maxnum < k) {
                            changeidx = f;
                            maxnum = k;
                            }
                        }
                    }
                }
            }
            for (int k=0;k<N;k++) {
                if (disarr[k] == 0) {
                    changeidx = k;
                    break;
                }
            }
            arr[changeidx] = inputarr[i];
            ans++;
        }
    }


    cout << ans << endl;
    return 0;
}
