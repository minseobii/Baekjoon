#include <iostream>
#include <vector>
#define N_MAX 5000000
using namespace std;
int N,K;

vector<bool> v(2300,true);
vector<int> prime;

void init() {
    v[0] = false;
    v[1] = false;
    for (int i=2;i*i<=N_MAX;i++) {
        if (v[i] == true) {
            prime.push_back(i);
            for (int j=2;(j*i)*(j*i)<=N_MAX;j++) {
                v[i*j] = false;
            }
        }
    }
}

void solve() {
    while(N--) {
        cin >> K;
        for (int i=0;i<prime.size();i++) {
            if (K <= prime[i]) break;

            while(K%prime[i] == 0) {
                cout << prime[i] << ' ';
                K /= prime[i];
            }
        }

        if (K != 1) cout << K << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    init();
    solve();

    return 0;
}
