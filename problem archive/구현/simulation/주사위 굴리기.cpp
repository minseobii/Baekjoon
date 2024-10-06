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
int N,M,K,x,y,arr[20][20];
int dice[6] = {0,0,0,0,0,0};
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

void roll_dice(int d) {
    if (d == 1) {
        int temp = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[2];
        dice[2] = temp;
    }
    else if (d == 2) {
        int temp = dice[5];
        dice[5] = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[3];
        dice[3] = temp;
    }
    else if (d == 3) {
        int temp = dice[5];
        dice[5] = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[1];
        dice[1] = temp;
    }
    else if (d == 4) {
        int temp = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[4];
        dice[4] = temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> x >> y >> K;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<K;i++) {
        int d;
        cin >> d;
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx<0 || ny<0 || nx>=N || ny>=M) continue;
        x = nx;
        y = ny;
        roll_dice(d);
        cout << dice[5] << '\n';

        if (arr[x][y] == 0) {
            arr[x][y] = dice[0];
        }
        else {
            dice[0] = arr[x][y];
            arr[x][y] = 0;
        }
    }
    return 0;
}
