#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int M,N;
int ans;
int zero = 0;

int arr[1001][1001];
int visit[1001][1001];

queue<tuple<int,int,int>> q;

int main() {
    cin >> M >> N;

    for (int b=0;b<N;b++) {
        for (int a=0;a<M;a++) {
            int k;
            cin >> k;
            if (k==0) {
                zero++;
            }
            if (k==1) {
                q.push(tuple<int,int,int>(a,b,0));
                
            }  
            arr[a][b] = k;
        }
    }

        while (!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int depth = get<2>(q.front());
            q.pop();
            
            if (!visit[i][j]) {
                if (i+1 < M && arr[i+1][j] == 0) {
                    arr[i+1][j] = 1;
                    q.push(tuple<int,int,int>(i+1,j,depth+1));
                    zero--;
                }
                if (j+1 < N && arr[i][j+1] == 0) {
                    arr[i][j+1] = 1;
                    q.push(tuple<int,int,int>(i,j+1,depth+1));
                    zero--;
                }
                if (i > 0 && arr[i-1][j] == 0) {
                    arr[i-1][j] = 1;
                    q.push(tuple<int,int,int>(i-1,j,depth+1));
                    zero--;
                }
                if (j > 0 && arr[i][j-1] == 0) {
                    arr[i][j-1] = 1;
                    q.push(tuple<int,int,int>(i,j-1,depth+1));
                    zero--;
                }
            }
            visit[i][j] = 1;
            ans = depth;
    }

    if (zero) {
        ans = -1;
    }

    cout << ans << endl;
    return 0;
}
