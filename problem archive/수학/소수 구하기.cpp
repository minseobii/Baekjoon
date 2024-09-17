#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool prime[1000001];

int M,N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;

    for (int i=2;i<1000001;i++) {
        prime[i] = true;
    }

    for (int i=2;i*i<=1000000;i++) {
        if (prime[i] == false) continue;

        for (int j=2;i*j<=1000000;j++) {
            prime[i*j] = false;
        }
    }

    for (int i=M;i<=N;i++) {
        if (prime[i]) cout << i << '\n';
    }
    return 0;
}
