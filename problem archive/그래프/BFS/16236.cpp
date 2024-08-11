#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,ans;
int arr[20][20];
vector<pair<int, int>> v[7];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

struct PAIR {
    int i,j,dis;
};

struct SHARK {
    int i,j;
    int size = 2;
    int full = 0;
};

SHARK shark;

int BFS(int a, int b) {
    int visit[20][20] = {0,};
    queue<PAIR> q;
    PAIR pair = {shark.i,shark.j,0};
    q.push(pair);
    visit[shark.i][shark.j] = 1;

    while(!q.empty()) {
        int x = q.front().i;
        int y = q.front().j;
        int dis = q.front().dis;
        q.pop();

        for (int k=0;k<4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny] == 1 || arr[nx][ny] > shark.size) {
                continue;
            }

            if (nx == a && ny == b) {
                return dis + 1;
            }

            visit[nx][ny] = 1;
            PAIR newpair = {nx,ny,dis+1};
            q.push(newpair);
        }
    }
    return 0;
}

bool FindFish() {
    int tempi = -1;
    int tempj = -1;
    int tempdis = -1;

    for (int a=1;a<min(shark.size,7);a++) {
        for (int b=0;b<v[a].size();b++) {
            int nx = v[a][b].first;
            int ny = v[a][b].second;
            int dis = 0;
            if (arr[nx][ny] > 0) {
                dis = BFS(nx, ny);
            }
            if (dis > 0) {
                if (tempdis == -1) {
                    tempdis = dis;
                    tempi = nx;
                    tempj = ny;
                }
                else if (tempdis == dis) {
                    if (tempi == nx) {
                        if (tempj > ny) {
                            tempdis = dis;
                            tempi = nx;
                            tempj = ny;
                        }
                    }
                    else if (tempi > nx) {
                        tempdis = dis;
                        tempi = nx;
                        tempj = ny;
                    }
                }
                else if (tempdis > dis) {
                    tempdis = dis;
                    tempi = nx;
                    tempj = ny;
                }
            }
        }
    }
    
    

    if (tempdis != -1) {
        arr[tempi][tempj] = 0;
        shark.i = tempi;
        shark.j = tempj;
        shark.full += 1;
        if (shark.full == shark.size) {
            shark.size += 1;
            shark.full = 0;
        }
        ans += tempdis;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int a;
            cin >> a;
            if (a == 9) {
                shark.i = i;
                shark.j = j;
                a = 0;
            }
            else if (a) {
                v[a].push_back({i,j});
            }
            arr[i][j] = a;
        }
    }

    while(FindFish()) {}

    cout << ans << endl;
    return 0;
}
