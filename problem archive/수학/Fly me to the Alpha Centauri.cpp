#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    while(T--) {
        int x,y,n;
        cin >> x >> y;
        n = y-x;
        double root = floor(sqrt(n));

        if (root*root == n) {
            cout << 2*root-1 << '\n';
        }
        else {
            if (n <= (root*root) + root) {
                cout << 2*root << '\n';
            }
            else cout << 2*root+1 << '\n';
        }
    }
    return 0;
}
