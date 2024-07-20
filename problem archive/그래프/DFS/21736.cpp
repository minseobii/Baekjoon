#include <iostream>
using namespace std;
int N, M;
char arr[601][601];
int visit[601][601];
int ans=0;

void DFS(int x, int y) {
    if (arr[x][y] == 'P') {
        ans++;
    }
    if (x+1 < N && (arr[x+1][y] == 'O' || arr[x+1][y] == 'P') && visit[x+1][y] == 0) {
        visit[x+1][y] = 1;
        DFS(x+1,y);
    }
    if (y+1 < M && (arr[x][y+1] == 'O' || arr[x][y+1] == 'P') && visit[x][y+1] == 0) {
        visit[x][y+1] = 1;
        DFS(x,y+1);
    }
    if (x > 0 && (arr[x-1][y] == 'O' || arr[x-1][y] == 'P') && visit[x-1][y] == 0) {
        visit[x-1][y] = 1;
        DFS(x-1,y);
    }
    if (y > 0 && (arr[x][y-1] == 'O' || arr[x][y-1] == 'P') && visit[x][y-1] == 0) {
        visit[x][y-1] = 1;
        DFS(x,y-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    pair<int, int> DoYune;
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            cin >> arr[i][j];
            visit[i][j] = 0;
            if (arr[i][j] == 'I') {
                DoYune = {i, j};
            }
        }
    }

    visit[DoYune.first][DoYune. second] = 1;
    DFS(DoYune.first, DoYune. second);

    if (ans == 0) {
        cout << "TT" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
