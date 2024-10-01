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
int N,M;
int ans = -1;
int arr[9][9];
int dr[17];
int dc[17];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    unordered_map<int,bool> m;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    int idx = 0;
    for (int i=-8;i<=8;i++) {
        dr[idx] = i;
        dc[idx] = i;
        idx++;
    }

    for (int i=0;i<=31622;i++) {
        m[i*i] = true;
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            for (int r=0;r<17;r++) {
                for (int c=0;c<17;c++) {
                    if (r == 8 && c == 8) continue;
                    int num = 0;
                    int ni = i;
                    int nj = j;
                    while(ni >= 0 && nj >= 0 && ni < N && nj < M) {
                        num = num * 10 + arr[ni][nj];
                        if (m[num]) ans = max(ans, num);

                        ni += dr[r];
                        nj += dc[c];
                    }  
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
