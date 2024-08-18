#include <iostream>
#include <map>
using namespace std;
int T,N,M,sign;
long long ans;
int A[1000];
int B[1000];
int sumA[1001];
int sumB[1001];

map<int,int> sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
        sumA[i+1] = sumA[i] + A[i];
    }
    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> B[i];
        sumB[i+1] = sumB[i] + B[i];
    }

    for (int i=1;i<=N;i++) {
        for (int j=0;j<i;j++) {
            int temp = sumA[i]-sumA[j];
            sum[temp]++;
        }
    }

    for (int i=1;i<=M;i++) {
        for (int j=0;j<i;j++) {
            int temp = T - (sumB[i]-sumB[j]);
            if (sum[temp]) {
                ans += sum[temp];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
