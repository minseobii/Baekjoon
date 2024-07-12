#include <iostream>
using namespace std;
int N;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N];

    arr[0]=1;
    int subarr[4] = {0,0,0,0};

    for (int i=1;i<N;i++) {
        int num = i+1;
        int temparr[4] = {0,1,2,3};

        for (int i=0;i<4;i++) {
            if (subarr[i] == 1) {
                temparr[i] = 0;
                subarr[i] = 0;
            }
        }

        for (int j=1;j<=num/2;j++) {
            int left = i - (j*2 - 1);
            for (int k=0;k<j;k++) {
                if (k == j-1){
                    temparr[arr[i-j]] = 0;
                }
                else {
                    if (arr[left+k] == arr[left+k+j]) {
                        continue;
                    }
                    else {
                        break;
                    }
                }
            }
        }

        int find = 0;

        for (int n=1;n<4;n++) {
            if (temparr[n] > 0) {
                arr[i] = temparr[n];
                find =1;
                break;
            } 
        }

        if (find == 0) {
            subarr[arr[i-1]] = 1;
            i -= 2;
        }
    }

    for (int i=0;i<N;i++) {
        cout << arr[i];
    }    
    cout << endl;
    return 0;
}
