#include <iostream>
#include <queue>
using namespace std;

int N,K,ans;
int arr[100001];
int visit[100001];

struct PAIR{
    int i,depth;
};

int main(){
    cin >> N >> K;
    queue<PAIR> q;          
    PAIR pair = {N,0};
    if (N != K) {
        q.push(pair);
    }
    else {
        ans = 1;
    }

    visit[N] = 1;
    arr[N] = 0;

    while (!q.empty()) {
        int nx;
        int x = q.front().i;
        int depth = q.front().depth;
        q.pop();
        
        if (x == K) {
          if (arr[K] == 0) {
            arr[K] = depth;
            ans = 1;
          }
          else if (arr[K] == depth) {
            ans++;
          }
          else if (arr[K] > depth) {
            arr[K] = depth;
            ans = 1;
          }
        }

        nx = x-1;
        if (x > 0 && (visit[nx] == 0 || (visit[nx] == 1 && arr[nx] >= depth+1))) {
            visit[nx] = 1;
            arr[nx] = depth+1;
            PAIR newpair = {nx, arr[nx]};
            q.push(newpair);
        }

        nx = x+1;
        if (x < 100000 && (visit[nx] == 0 || (visit[nx] == 1 && arr[nx] >= depth+1))) {
            visit[nx] = 1;
            arr[nx] = depth+1;
            PAIR newpair = {nx, arr[nx]};
            q.push(newpair);
        }

        nx = 2*x;
        if (nx <= 100000 && (visit[nx] == 0 || (visit[nx] == 1 && arr[nx] >= depth+1))) {
            visit[nx] = 1;
            arr[nx] = depth+1;
            PAIR newpair = {nx, arr[nx]};
            q.push(newpair);
        }
    }
    cout << arr[K] << endl;
    cout << ans << endl;
    return 0;
}