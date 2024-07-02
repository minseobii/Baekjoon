#include <iostream>
#include <queue>
using namespace std;

int R,C;
char arr[21][21];
int ans=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int alphabet[27];

int DFS(int x, int y) {
    for (int i=0;i<4;i++) {
        if (alphabet[arr[x+dx[i]][y+dy[i]]-'A'] == 0 && )
    }
}

int main() {
    cin >> R >> C;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> arr[i][j];
        }
    }
    DFS(0,0);

    cout << DFS;
    return 0;
}