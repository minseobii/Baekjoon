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
int N,M,area,ans,arr[8][8],A[8][8];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

struct CCTV {
    int x,y,num;
};
vector<CCTV> v;

void check(int x ,int y, int dir, int dif) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    while(1) {
        if (nx<0 || ny<0 || nx>=N || ny>=M || arr[nx][ny] == 6) break;
        A[nx][ny] += dif;
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }
}

void dfs(int cnt) {
    if (cnt == v.size()) {
        int count = area;
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                if (arr[i][j] == 0 && A[i][j]) count--;
            }
        }
        ans = min(ans, count);
        return;
    } 

    int x = v[cnt].x;
    int y = v[cnt].y;
    int num = v[cnt].num;

    if (num == 1) {
        for (int i=0;i<4;i++) {
            check(x,y,i,1);
            dfs(cnt+1);
            check(x,y,i,-1);
        }
    }
    else if (num == 2) {
        for (int i=0;i<2;i++) {
            check(x,y,i,1);
            check(x,y,i+2,1);
            dfs(cnt+1);
            check(x,y,i,-1);
            check(x,y,i+2,-1);
        }
    }
    else if (num == 3) {
        for (int i=0;i<4;i++) {
            check(x,y,i,1);
            check(x,y,(i+1)%4,1);
            dfs(cnt+1);
            check(x,y,i,-1);
            check(x,y,(i+1)%4,-1);
        }
    }
    else if (num == 4) {
        for (int i=0;i<4;i++) {
            check(x,y,i,1);
            check(x,y,(i+1)%4,1);
            check(x,y,(i+2)%4,1);
            dfs(cnt+1);
            check(x,y,i,-1);
            check(x,y,(i+1)%4,-1);
            check(x,y,(i+2)%4,-1);
        }
    }
    else if (num == 5) {
        check(x,y,0,1);
        check(x,y,1,1);
        check(x,y,2,1);
        check(x,y,3,1);
        dfs(cnt+1);
        check(x,y,0,-1);
        check(x,y,1,-1);
        check(x,y,2,-1);
        check(x,y,3,-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    ans = N*M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 6) ans--;
            else if (arr[i][j] > 0){
                ans--;
                CCTV cctv = {i,j,arr[i][j]};
                v.push_back(cctv);
            }
        }
    }
    area = ans;
    dfs(0);

    cout << ans << '\n';
    return 0;
}
