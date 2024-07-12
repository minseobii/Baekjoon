#include <iostream>
#include <queue>
using namespace std;
int N,M;
char arr[51][51];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int ans=0;

struct PAIR{
    int i,j,depth;
};

int BFS(int i,int j){
    int visit[51][51] = {0,};
    int max=0;
    queue<PAIR> q;
    visit[i][j] = 1;
                
    PAIR pair = {i,j,0};
    q.push(pair);

    while (!q.empty()) {

        int a = q.front().i;
        int b = q.front().j;
        int depth = q.front().depth;
        q.pop();

        if (depth > max) max = depth;

        for (int k=0;k<4;k++) {
                        
            int new_a = a + dy[k];
            int new_b = b + dx[k];

            if (new_a < 0 || new_b < 0 || new_a+1 > N || new_b+1 > M || visit[new_a][new_b] == 1 || arr[new_a][new_b] == 'W') {
                continue;
            }
            PAIR new_pair = {new_a,new_b,depth+1};
            q.push(new_pair);
            visit[new_a][new_b] = 1;
        }
    }
    return max;
}

int main() {
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            char a;
            cin >> a;
            arr[i][j] = a;
        }
    }
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            if (arr[i][j] == 'L') {
               int tmax = BFS(i,j);
               if (tmax > ans) {
                ans = tmax;
               }          
            }
        }
    }  

    cout << ans << endl;
    return 0;
}
