#include <iostream>
#include <vector>
using namespace std;
long long N;
long long ans = 1;

vector<bool> v(1000001,true);
vector<long long> prime;

long long p(int a, int b) {
    long long temp = 1;
    for (int i=0;i<b;i++) {
        temp *= a;
    }
    return temp;
}

void init() {
    v[0] = false;
    v[1] = false;
    for (long long i=2;i*i<=N;i++) {
        if (v[i] == true) {
            prime.push_back(i);
            for (long long j=2;(j*i)*(j*i)<=N;j++) {
                v[i*j] = false;
            }
        }  
    }

    
}

void solve() {
    long long temp = N;
    for (int i=0;i<prime.size();i++) {
        int count = 0;
        while (temp%prime[i] == 0) {
            count++;
            temp /= prime[i];
        }

        if (count) ans *= p(prime[i],count) - p(prime[i],count-1);
    }

    if (temp != 1) ans *= temp - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    init();
    solve();

    cout << ans << endl;
    return 0;
}
