#include <iostream>
using namespace std;
int T;

int gcd(int a, int b) {
    int c;
    while(b!=0){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        int M,N,x,y;
        int find = 0;
        cin >> M >> N >> x >> y;
        int lcm = M * N / gcd(M,N);
        for (int i=0;i<=lcm/N;i++) {
            int a = ((N*i)+y-x)/M;
            if (((M*a)+x) == ((N*i)+y)) {
                find = 1;
                cout << (N*i)+y << '\n';
                break;
            }
        }
        if (find == 0) {
            cout << -1 << '\n';
        }
    }
    return 0;
}
