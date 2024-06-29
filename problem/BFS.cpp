#include <iostream>
#include <queue>
using namespace std;

int N,M;
char arr[51][51];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

struct PAIR{
    int i,j,depth;
};

int BFS(int i,int j){
    int visit[51][51] = {0,};
    queue<PAIR> q;          
    PAIR pair = {i,j,0};
    q.push(pair);

    visit[i][j] = 1;

    while (!q.empty()) {

        int x = q.front().i;
        int y = q.front().j;
        int depth = q.front().depth;
        q.pop();

        for (int k=0;k<4;k++) {
                        
            int nx = x + dy[k];
            int ny = y + dx[k];

            if (nx < 0 || ny < 0 || nx+1 > N || ny+1 > M || visit[nx][ny] == 1 || arr[nx][ny] == 'W') {
                continue;
            }
            PAIR newpair = {nx,ny,depth+1};
            q.push(newpair);
            visit[nx][ny] = 1;
        }
    }
    return 0;
}