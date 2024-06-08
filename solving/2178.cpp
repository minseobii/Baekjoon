#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int N,M;
int ans=0;
int arr[101][101];
int visit[101][101];
queue<tuple<int,int,int>> q;

int main() {
    cin >> N >> M;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=M;j++) {
            char a;
            cin >> a;
            arr[i][j] = a - '0';
        }
    }

    q.push(tuple<int,int,int>(1,1,1));

    while (!q.empty()) {
        int i = get<0>(q.front());
        int j = get<1>(q.front());
        int depth = get<2>(q.front());
        q.pop();

        int trigger=0;

        if(i == N && j == M) {
            if (ans == 0 || ans > depth) {
                ans = depth;
            }
            trigger = 1;
        }

        if (visit[i][j] == 0) {
            if (!trigger) {
                if (i < N && arr[i+1][j] == 1) {
                    q.push(tuple<int,int,int>(i+1,j,depth+1));
                }
                if (j < M && arr[i][j+1] == 1) {
                    q.push(tuple<int,int,int>(i,j+1,depth+1));
                }
                if (i > 1 && arr[i-1][j] == 1) {
                    q.push(tuple<int,int,int>(i-1,j,depth+1));
                }
                if (i > 1 && arr[i][j-1] == 1) {
                    q.push(tuple<int,int,int>(i,j-1,depth+1));
                }
            }
        }
        visit[i][j] = 1;
    
    }
    cout << ans << endl;
    return 0;
}
