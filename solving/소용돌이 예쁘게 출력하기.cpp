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
int arr[50][5];

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
    int r1,r2,c1,c2,Max;
    cin >> r1 >> c1 >> r2 >> c2;
    
    for (int i=0;i<=r2-r1;i++) {
        for (int j=0;j<=c2-c1;j++) {
            arr[i][j] = getnum(i+r1,j+c1);
            Max = max(Max, arr[i][j]);
        }
    }

    int count = 0;
    while(Max > 0) {
        count += 1;
        Max /= 10;
    }

    for (int i=0;i<=r2-r1;i++) {
        for (int j=0;j<=c2-c1;j++) {
            string s = to_string(arr[i][j]);
            for (int k=0;k<count - s.length();k++) {
                cout << ' ';
            }
            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}
