#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int arr[N] = {0,};
    int subarr[N] = {0,};
    for (int i=0;i<N;i++) {
        if (i < M) {
            subarr[i] = 1;
        }
        else {
            subarr[i] = 0;
        }
        arr[i] = i+1;
    }
    do { 
        for (int i=0;i<N;i++) {
            if (subarr[i]) {
                cout << arr[i] << ' ';
            }
        }
        cout << '\n';
        
    } while(prev_permutation(subarr,subarr+N));
    return 0;
}
