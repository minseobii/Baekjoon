#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int N;
long long ans_num;
long long arr[300000];
long long ans[300000];

long long sum[300001];

void memoization() {
    for (int i=1;i<=N;i++) {
        if (i == 1) {
            sum[i] = 1;
        }
        else {
            sum[i] = ((sum[i-1]*2)+1) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);

    memoization();

    for (int i=0;i<N;i++) {
        if (i == 0) ans[0] = 0;
        else {
            long long a = arr[i] - arr[i-1];
            ans[i] = (((ans[i-1] * 2) % MOD) + (a * sum[i]) % MOD) % MOD;
            ans_num = (ans_num + ans[i]) % MOD;
        }
    }

    cout << ans_num << endl;
    return 0;
}
