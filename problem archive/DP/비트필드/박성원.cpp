#include <iostream>
using namespace std;
int N,K;
pair<string,int> arr[15];

int memozation[51];
int subarr[15];
long long DP[1 << 15][101];

void memozation_init() {
    for (int i=0;i<51;i++) {
        if (i == 0) memozation[i] = 1;
        else memozation[i] = (memozation[i-1] * 10) % K;
    }
}

void arr_init() {
    for (int i=0;i<N;i++) {
        int rem = 0;
        int idx = 0;
        for (int j=0;j<arr[i].second;j++) {
            rem = ((arr[i].first[idx] - '0') + (rem * 10)) % K;
            idx++;
        }

        subarr[i] = rem;
    }
}

void dp_init() {
    for (int i=0;i<(1 << N);i++) {
        for (int j=0;j<100;j++) {
            DP[i][j] = -1;
        }
    }
}

long long factorial(int n) {
    long long a = 1;
    for (int i=0;i<n;i++) {
        a *= (i+1);
    }
    return a;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

long long dp(int bit, int rem) {
    if (bit+1 == (1 << N)) return rem == 0;
    if (DP[bit][rem] != -1) return DP[bit][rem];

    DP[bit][rem] = 0;

    for (int i=0;i<N;i++) {
        if ((1 << i) & bit) continue;
        int digit = arr[i].second;
        DP[bit][rem] += dp((1 << i) | bit, ((rem * memozation[digit]) + subarr[i]) % K);
    }

    return DP[bit][rem];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i].first;
        arr[i].second = arr[i].first.length();
    }
    cin >> K;
    
    memozation_init();
    arr_init();
    dp_init();

    long long up = dp(0,0);
    long long down = factorial(N);
    long long gcd_num = gcd(down,up);

    cout << up/gcd_num << '/' << down/gcd_num;
    return 0;
}
