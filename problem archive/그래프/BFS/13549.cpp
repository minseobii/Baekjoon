#include <iostream>
#include <queue>
using namespace std;

int N,K;

struct PAIR{
    int i,time;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int ans=100001;
    int visit[100001] = {0,};
    int visittime[100001] = {0,};
    queue<PAIR> q;          
    PAIR pair = {N,0};
    q.push(pair);

    visit[N] = 1;

    while (!q.empty()) {
        int nx;
        int x = q.front().i;
        int time = q.front().time;
        q.pop();

        if (x == K) {
            ans = min(ans, time);
            continue;
        }

        nx = x + 1;
        if (nx >= 0 && nx <= 100000 && (visit[nx] == 0 || ((visit[nx] == 1) && (visittime[nx] > time+1)))) {
            PAIR newpair = {nx,time+1};
            q.push(newpair);
            visit[nx] = 1;
            visittime[nx] = time+1;
        }
        nx = x - 1;
        if (nx >= 0 && nx <= 100000 && (visit[nx] == 0 || ((visit[nx] == 1) && (visittime[nx] > time+1)))) {
            PAIR newpair = {nx,time+1};
            q.push(newpair);
            visit[nx] = 1;
            visittime[nx] = time+1;
        }
        nx = 2*x;
        if (nx >= 0 && nx <= 100000 && (visit[nx] == 0 || ((visit[nx] == 1) && (visittime[nx] > time)))) {
            PAIR newpair = {nx,time};
            q.push(newpair);
            visit[nx] = 1;
            visittime[nx] = time;
        }
    }

    cout << ans << endl;
    return 0;
}