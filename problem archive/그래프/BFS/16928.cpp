#include <iostream>
#include <queue>
using namespace std;

int N,M,ans;
int arr[101];

struct PAIR{
    int i,depth;
};

int main(){
    cin >> N >> M;

    for (int i=0;i<N+M;i++) {
        int first,second;
        cin >> first >> second;
        arr[first] = second;
    }

    int visit[101] = {0,};
    queue<PAIR> q;          
    PAIR pair = {1,0};
    q.push(pair);

    visit[1] = 1;

    while (!q.empty()) {
        int x = q.front().i;
        int depth = q.front().depth;
        q.pop();

        if (x == 100) {
            ans = depth;
            break;
        }

        for (int k=1;k<=6;k++) {  
            int nx = x + k;

            if (arr[nx]) {
                nx = arr[nx];
            }

            if (nx > 100 || visit[nx] == 1) {
                continue;
            }
            PAIR newpair = {nx,depth+1};
            q.push(newpair);
            visit[nx] = 1;
        }
    }

    cout << ans << endl;
    return 0;
}