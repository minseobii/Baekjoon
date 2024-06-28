#include <iostream>
#include <queue>
using namespace std;
int N,M;
char arr[51][51];
int group[51][51];
int group_num=1;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int ans=0;

struct PAIR{
    int i,j,depth;
};

int checkmindepth(int i,int j,int x,int y){
    int visit[51][51];
    int min=0;
    queue<PAIR> q;
                
    PAIR pair = {i,j,0};
    q.push(pair);

    while (!q.empty()) {

        int a = q.front().i;
        int b = q.front().j;
        int depth = q.front().depth;
        q.pop();

        if (a==x && b==y) {
            if (min == 0) {
                min = depth;
            }
            else {
                if (min > depth) {
                    min = depth;
                }
            }
            continue;
        }

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
    return min;
}

void putingroup(int i, int j) {
    int visit[51][51];
    int group_idx=0;
    queue<PAIR> q;
                
    PAIR pair = {i,j,0};
    q.push(pair);

    while (!q.empty()) {

        int a = q.front().i;
        int b = q.front().j;
        q.pop();

        group[a][b] = group_num;
        

        for (int k=0;k<4;k++) {
                        
            int new_a = a + dy[k];
            int new_b = b + dx[k];

            if (new_a < 0 || new_b < 0 || new_a+1 > N || new_b+1 > M || visit[new_a][new_b] == 1 || arr[new_a][new_b] == 'W') {
                continue;
            }
            PAIR new_pair = {new_a,new_b,0};
            q.push(new_pair);
            visit[new_a][new_b] = 1;
        }
    }
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
               if (group[i][j] == 0) {
                putingroup(i,j);
                group_num++;
               }          
            }
        }
    }

    for(int i=1;i<group_num;i++) {
        for(int a=0;a<N;a++) {
            for(int b=0;b<M;b++) {
                if (group[a][b] == i) {
                    for (int x=a;x<N;x++) {
                        for (int y=b+1;b<M;b++) {
                            if (group[x][y] == i) {
                                int depth = checkmindepth(a,b,x,y);
                                if (ans > depth) {
                                    ans = depth;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    
    

    cout << ans << endl;
    return 0;
}
