#include <iostream>
using namespace std;
int T,M,N,K;
int arr[51][51];

int ans = 0;

int search(int i, int j) {
    if (arr[i][j]) {
        arr[i][j] = 0;

        if (i+1 < M) {
            search(i+1,j);
        }
        
        if (j+1 < N) {
            search(i,j+1);
        }
        
        if (i > 0) {
            search(i-1,j);
        }
        
        if (j > 0) {
            search(i,j-1);
        }
    }
}

int main() {
    cin >> T 
    for (int t=0;t<T;t++) {
        ans = 0;
        cin >> M >> N >> K;

        for (int i=0;i<K;i++) {
            int a,b;
            cin >> a >> b;
            arr[a][b] = 1;
        }

        for (int i=0;i<M;i++) {
            for (int j=0;j<N;j++) {
                if (arr[i][j]) {
                    search(i,j);
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }

    
    return 0;
}
