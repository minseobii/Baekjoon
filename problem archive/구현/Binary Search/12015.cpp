#include <iostream>
#include <algorithm>
using namespace std;
int N,ans;
int n = 1;
int arr[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        int k;
        cin >> k;
        
        if (arr[n-1] < k) arr[n++] = k;
        else {
            int a = upper_bound(arr,arr+n,k) - arr;
            int b = lower_bound(arr,arr+n,k) - arr;
            if (a == b) arr[a] = k;
        }
    }
    cout << n-1 << endl;
    return 0;
}
