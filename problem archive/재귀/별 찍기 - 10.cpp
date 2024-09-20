#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans;
bool arr[2200][2200];

void cal(int r, int c, int x) {
    if (x == 3) {
        for (int i=r;i<r+3;i++) {
            for (int j=c;j<c+3;j++) {
                if (i == r+1 && j == c+1) continue;
                else arr[i][j] = true;
            }
        }
    }
    else {
        int k = x/3;
        for (int i=r;i<r+x;i+=k) {
            for (int j=c;j<c+x;j+=k) {
                if (i == r+k && j == c+k) continue;
                else cal(i,j,k);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cal(0,0,N);

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (arr[i][j]) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
