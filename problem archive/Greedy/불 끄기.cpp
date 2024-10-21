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
int ans = -1;
int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,-1,1};
bool A[10][10];

void push_button(int r, int c) {
    for (int k=0;k<5;k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (nr>=0 && nc>=0 && nr<10 && nc<10) A[nr][nc] = !A[nr][nc];
    }
}

void DFS(int row, int count) {
    if (row == 9) {
        for (int i=0;i<10;i++) {
            if (A[9][i]) return;
        }

        if (ans == -1) ans = count;
        else ans = min(ans, count);
        return;
    }

    bool subarr[10] = {0,};
    int temp_count = 0;
    for (int i=0;i<10;i++) {
        if (A[row][i]) {
            subarr[i] = true;
            push_button(row+1,i);
            temp_count++;
        }
    }
    DFS(row+1, count + temp_count);
    for (int i=0;i<10;i++) {
        if (subarr[i]) {
            push_button(row+1,i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            char c;
            cin >> c;
            if (c == 'O') {
                A[i][j] = true;
            }
        }
    }

    for (int i=0;i<1024;i++) {
        int count = 0;
        for (int k=0;k<10;k++) {
            if ((i >> k) & 1) {
                push_button(0,k);
                count++;
            }
        }
        DFS(0,count);
        for (int k=0;k<10;k++) {
            if ((i >> k) & 1) push_button(0,k);
        }
    }

    cout << ans << '\n';
    return 0;
}
