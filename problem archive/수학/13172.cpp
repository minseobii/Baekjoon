#include <iostream>
#define X 1000000007
using namespace std;
int M;
long long upper;
long long lower;
long long ans;

long long square(long long u, long long l) {
    long long B = X-2;
    long long temp = 1;
    while(B > 0) {
        if (B%2) {
            temp = (temp * l) % X;
        }
        l = (l * l) % X;
        B /= 2;
    }
    return ((u * temp) % X);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;
    while (M--) {
        long long u,l;
        cin >> l >> u;
        ans = (ans + square(u,l)) % X;
    }

    cout << ans << endl;
    return 0;
}
