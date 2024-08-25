#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N,M;
int C = 1;
int arr[1000][1000];
int space[1000][1000];
int parent[1000][1000];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void cal_space(int i, int j) {
    if (arr[i][j] || space[i][j]) return;

    queue<pair<int,int>> q;
    queue<pair<int,int>> range;
    int count = 1;
    q.push({i,j});
    range.push({i,j});
    space[i][j] = 1;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k=0;k<4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx<0 || ny<0 || nx>=N || ny>=M || arr[nx][ny] || space[nx][ny]) {
                continue;
            }
            q.push({nx,ny});
            range.push({nx,ny});
            space[nx][ny] = 1;
            count++;
        }
    }
    while(!range.empty()) {
        space[range.front().first][range.front().second] = count;
        parent[range.front().first][range.front().second] = C;
        range.pop();
    }
    C++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cal_space(i,j);
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 0) {
                cout << 0;
                continue;
            }

            int temp = 1;
            vector<pair<int,int>> v;
            for (int k=0;k<4;k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                bool find = false;

                if (ni<0 || nj<0 || ni>=N || nj>=M || arr[ni][nj]) {
                    continue;
                }

                for (int u=0;u<v.size();u++) {
                    if (parent[v[u].first][v[u].second] == parent[ni][nj]) find = true;
                }

                if (find) continue;

                temp += space[ni][nj];
                v.push_back({ni,nj});
            }
            cout << temp % 10;
        }
        cout << '\n';
    }
    return 0;
}
