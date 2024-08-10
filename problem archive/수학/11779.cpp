#include <iostream>
#define X 1000000007
using namespace std;
long long N;
long long ans[2] = {1,0};
long long x[2] = {1,1};

void cal(long long A[], long long B[]) {
    long long a = A[0];
    long long b = A[1];
    long long c = B[0];
    long long d = B[1];

    A[0] = (((a*c) % X) + ((((b*d) % X)*5) % X)) % X;
    A[1] = (((b*c) % X) + ((a*d) % X)) % X;
}

void Fibo(long long n) {
    while(n>0) {
        if (n%2) {
            cal(ans,x);   
        }
        cal(x,x);
        n/=2;
    }
}

long long square(long long n, long long k) {
    long long temp1 = 1;
    long long temp2 = k;
    while(n>0) {
        if (n%2) {
            temp1 = (temp1 * temp2) % X;
        }
        temp2 = (temp2 * temp2) % X;
        n /= 2;
    }
    return temp1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    if (N == 0 || N == 1) {
        cout << N << endl;
    }
    else {
        Fibo(N);
        cout << (((2*ans[1]) % X) * (square(X-2, square(N, 2))) % X) % X << endl;
    }
    return 0;
}
