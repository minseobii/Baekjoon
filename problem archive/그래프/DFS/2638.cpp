#include <iostream>
using namespace std;
int N,M,Cheeze;
int arr[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int ans;

int visit[100][100];

bool DFS(int x,int y) {
    visit[x][y] = 1;
    if (x == 0 || x == N-1 || y == 0 || y == M-1) {
        return true;
    }

    for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (arr[nx][ny] == 0 && visit[nx][ny] == 0) {
            if (DFS(nx,ny)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                Cheeze++;
            }
        }
    }

    while(Cheeze) {
        int temp[100][100] = {0,};
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                if (arr[i][j]) {
                    int count=0;
                    for (int k=0;k<4;k++) {
                        if (arr[i+dx[k]][j+dy[k]] == 0) {
                            for (int i=0;i<N;i++) {
                                for (int j=0;j<M;j++) {
                                    visit[i][j] = 0;
                                }
                            }
                            if (DFS(i+dx[k],j+dy[k])) {
                                count++;
                            }
                        }
                    }
                    if (count >= 2) {
                        temp[i][j] = -1;
                        Cheeze--;
                    }
                }
            }
        }

        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                arr[i][j] += temp[i][j];
            }
        }  
        ans++;
    }

    cout << ans << endl;
    return 0;
}
