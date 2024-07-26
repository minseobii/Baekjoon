#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    int arr[N][M];

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (j+3 < M) {
                ans = max(ans,arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3]);
            }
            if (i+3 < N) {
                ans = max(ans,arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j]);
            }
            if (i+1 < N && j+2 < M) {
                int temparr[6] = {arr[i][j],arr[i][j+1],arr[i][j+2],arr[i+1][j],arr[i+1][j+1],arr[i+1][j+2]};
                int subarr[6] = {0,0,1,1,1,1}; 
                do { 
                    int tempans=0;
                    if ((!(subarr[0])&&(!subarr[4])) || (!(subarr[1])&&(!subarr[5])) || (!(subarr[2])&&(!subarr[4])) || (!(subarr[1])&&(!subarr[3])) || (!(subarr[1])&&(!subarr[4]))) {
                        continue;
                    }
                    else {
                        for (int k=0;k<6;k++) {
                            if (subarr[k]) {
                                tempans += temparr[k];
                            }
                        }
                        ans = max(ans, tempans);
                    }
                } while(next_permutation(subarr,subarr+6));
            }
            if (i+2 < N && j+1 < M) {
                int temparr[6] = {arr[i][j],arr[i+1][j],arr[i+2][j],arr[i][j+1],arr[i+1][j+1],arr[i+2][j+1]};
                int subarr[6] = {0,0,1,1,1,1}; 
                do { 
                    int tempans=0;
                    if ((!(subarr[0])&&(!subarr[4])) || (!(subarr[1])&&(!subarr[5])) || (!(subarr[2])&&(!subarr[4])) || (!(subarr[1])&&(!subarr[3])) || (!(subarr[1])&&(!subarr[4]))) {
                        continue;
                    }
                    else {
                        for (int k=0;k<6;k++) {
                            if (subarr[k]) {
                                tempans += temparr[k];
                            }
                        }
                        ans = max(ans, tempans);
                    }
                } while(next_permutation(subarr,subarr+6));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
