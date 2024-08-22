#include <iostream>
#include <algorithm>
#define INF 3000000001
using namespace std;
int N;
long long Value;
int arr[5001];
int ans[3];

long long cal(long long a, long long b, long long c) {
    return llabs(a+b+c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    Value = INF;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        int l = 0;
        int r = N-1;
        
        while (l < r) {
            if (l == i) {
                l++;
                continue;
            }
            else if (r == i) {
                r--;
                continue;
            }

            int sum = cal(arr[i],arr[r],arr[l]);
            if (Value > sum) {
                Value = sum;
                ans[0] = arr[i];
                ans[1] = arr[r];
                ans[2] = arr[l];
            }

            if (l+1 == r) break;

            long long suml = cal(arr[i],arr[l+1],arr[r]);
            long long sumr = cal(arr[i],arr[l],arr[r-1]);

            if (suml < sumr) l++;
            else r--; 
        }
    }

    sort(ans,ans+3);

    for (int i=0;i<3;i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
