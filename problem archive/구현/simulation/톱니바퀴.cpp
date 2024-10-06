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
int ans,K,A[4][8];
bool visit[4] = {0,};
map<int,int> m;

void spin_wheel(int num, int dir) {
    visit[num] = true;
    if (num-1 >=0 && !visit[num-1] && A[num-1][2] != A[num][6]) spin_wheel(num-1,m[dir]);
    if (num+1 <=3 && !visit[num+1] && A[num+1][6] != A[num][2]) spin_wheel(num+1,m[dir]);

    if (dir == 1) {
        int temp = A[num][0];
        A[num][0] = A[num][7];
        A[num][7] = A[num][6];
        A[num][6] = A[num][5];
        A[num][5] = A[num][4];
        A[num][4] = A[num][3];
        A[num][3] = A[num][2];
        A[num][2] = A[num][1];
        A[num][1] = temp;
    }
    else {
        int temp = A[num][0];
        A[num][0] = A[num][1];
        A[num][1] = A[num][2];
        A[num][2] = A[num][3];
        A[num][3] = A[num][4];
        A[num][4] = A[num][5];
        A[num][5] = A[num][6];
        A[num][6] = A[num][7];
        A[num][7] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    m[1] = -1;
    m[-1] = 1;
    for (int i=0;i<4;i++) {
        for (int j=0;j<8;j++) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }
    cin >> K;
    for (int i=0;i<K;i++) {
        fill(visit,visit+4,false);
        int x,d;
        cin >> x >> d;
        spin_wheel(x-1,d);
    }

    int count = 1;
    for (int i=0;i<4;i++) {
        ans += A[i][0] * count;
        count *= 2;
    }
    cout << ans << '\n';
    return 0;
}
