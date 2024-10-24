#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M,arr[100],dif[99];
vector<int> v;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
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
    

    for (int i=0;i<N-1;i++) {
        dif[i] = arr[i+1] - arr[i];
    }
    

    int k = dif[0];
    for (int i=1;i<=N-2;i++) {
        k = gcd(max(k, dif[i]), min(k, dif[i]));
    }


    for (int i=2;i*i<=k;i++) {
        if (i*i == k) {
            v.push_back(i);
            break;
        }
        while(k % i == 0) {
            v.push_back(i);
            v.push_back(k/i); 
        }
    }
    v.push_back(k);
    sort(v.begin(),v.end());
    for (int ans : v) {
        cout << ans << ' ';
    }
    return 0;
}
