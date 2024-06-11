#include <iostream>
#include <queue>
using namespace std;
int N,M;
char arr[51][51];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int ans;

struct PAIR{
    int i,j,depth;
};

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
                int arr_dis[51][51];
                arr[i][j] = -1;
                int visit[51][51];
                queue<PAIR> q;
                
                PAIR pair = {i,j,0};
                q.push(pair);

                while (!q.empty()) {

                    int a = q.front().i;
                    int b = q.front().j;
                    int depth = q.front().depth;
                    q.pop();

                    for (int k=0;k<4;k++) {
                        
                        int new_a = a + dy[k];
                        int new_b = b + dx[k];

                        int dis = arr_dis[new_a][new_b];
                        
                        if (dis != -1) {
                            if (dis == 0) {
                                dis = depth;
                            }
                            else {
                                if (dis > depth) {
                                    dis = depth;
                                }
                            }
                        }

                        arr[new_a][new_b] = dis;

                        if (new_a < 0 || new_b < 0 || new_a+1 > N || new_b+1 > M || visit[new_a][new_b] == 1 || arr[new_a][new_b] == 'W') {
                             continue;
                        }
                        PAIR new_pair = {new_a,new_b,depth+1};
                        q.push(new_pair);
                        visit[new_a][new_b] = 1;
                    }
                }
                int max=0;
                for (int dis_i=0;dis_i<51;dis_i++) {
                    for (int dis_j=0;dis_j<51;dis_j++) {
                        if (max < arr_dis[dis_i][dis_j]) {
                            max = arr_dis[dis_i][dis_j];
                        }
                    }
                }
                if (ans < max) {
                    ans = max;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
