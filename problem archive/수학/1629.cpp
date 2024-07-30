#include <iostream>
using namespace std;
int A,B,C;

long long divide(long long n) {
    if (n == 1) {
        return A % C;
    }
    long long divided = divide(n/2);
    if (n%2==1) {
        return (((divided*divided) % C) * (A % C)) % C;
    }
    return (divided*divided) % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> A >> B >> C;
    cout << divide(B) % C << endl;
    return 0;
}
