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
int r1,r2,c1,c2,Max;

int getnum(int r, int c) {
    int m = max(abs(r), abs(c));
    int num = (2*m-1) * (2*m-1);

    if (r == m) {
        num += c + m;
        c = -m;
    }
    if (c == -m) {
        num += r + m;
        r = -m;
    }
    if (r == -m) {
        num += m - c;
        c = m;
    }
    if (c == m) {
        num += m - r;
        r = m; 
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r1 >> c1 >> r2 >> c2;
    
    for (int i=0;i<=r2-r1;i++) {
        for (int j=0;j<=c2-c1;j++) {
            int k = getnum(i+r1,j+c1);
            Max = max(Max, k);
        }
    }

    int count = to_string(Max).length();

    for (int i=0;i<=r2-r1;i++) {
        for (int j=0;j<=c2-c1;j++) {
            int l = getnum(i+r1,j+c1);
            string s = to_string(l);
            for (int k=0;k<count - s.length();k++) {
                cout << ' ';
            }
            cout << l << ' ';
        }
        cout << '\n';
    }

    return 0;
}
