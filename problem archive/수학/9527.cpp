#include <iostream>
using namespace std;
long long sum[55];
long long A,B,ans;

long long square(int x) {
    long long k = 1;
    for (int i=0;i<x;i++) {
        k *= 2;
    }
    return k;
}

long long cal(long long x) {
    long long temp = x;
    long long val = 0;
    int count = 0;

    bool bit[55] = {0,};

    int i = 0;
    while(temp != 0) {
        if (temp & 1) {
            bit[i] = true;
        }
        temp = temp >> 1;
        i++;
    }

    for (int j=54;j>=0;j--) {
        if (bit[j]) {
            val += ((sum[j]+1) + (count*square(j)));
            count++;
        }
    }

    
    return val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B;
    long long k = 1;
    for (int i=1;i<55;i++) {
        if (i == 1) sum[1] = 1;
        else sum[i] = (sum[i-1]*2) + k;
        k *= 2;
    }

    ans = cal(B) - cal(A);
    int j = 0;
    while(A != 0) {
        if (A & 1) {
            ans++;
        }
        A = A >> 1;
        j++;
    }

    cout << ans << endl;
    return 0;
}
