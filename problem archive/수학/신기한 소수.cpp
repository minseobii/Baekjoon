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
int N;
vector<int> v[9];

bool isprime(int k) {
    for (int i=2;i*i<=k;i++) {
        if (k%i == 0) return false;
    }
    return true;
}

void cal(int n) {
    if (n == N) return;

    for (int j=0;j<v[n].size();j++) {
        for (int i=1;i<10;i+=2) {
            int k = v[n][j]*10+i;
            if (isprime(k)) v[n+1].push_back(k);
        }
    }
    cal(n+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(5);
    v[1].push_back(7);
    cal(1);

    for (int i=0;i<v[N].size();i++) {
        cout << v[N][i] << '\n';
    }

    return 0;
}
