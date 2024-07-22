#include <iostream>
#include <queue>
using namespace std;

int N,M,H;
int dh[6] = {0,0,0,0,-1,1,};
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};

int ans;
int zero=0;

struct PAIR{
    int h,i,j,depth;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;
    int arr[H][N][M];
    int visit[H][N][M] = {0,};

    queue<PAIR> q;          

    for (int h=0;h<H;h++) {
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                cin >> arr[h][i][j];
                if (arr[h][i][j] == 1) {
                    PAIR pair = {h,i,j,0};
                    visit[h][i][j] = 1;
                    q.push(pair);
                }
                else if (arr[h][i][j] == 0) {
                    zero++;
                }
            }
        }
    }

    while (!q.empty()) {
        int h = q.front().h;
        int x = q.front().i;
        int y = q.front().j;
        int depth = q.front().depth;
        q.pop();

        ans = depth;

        //cout << h << ' ' << x << ' ' << y << endl;

        for (int k=0;k<6;k++) {
            int nh = h + dh[k];            
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nh < 0 || nx < 0 || ny < 0 || nh+1 > H || nx+1 > N || ny+1 > M || visit[nh][nx][ny] == 1 || arr[nh][nx][ny] == -1) {
                continue;
            }
            PAIR newpair = {nh,nx,ny,depth+1};
            q.push(newpair);
            visit[nh][nx][ny] = 1;
            zero--;
        }
    }

    if (zero) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}