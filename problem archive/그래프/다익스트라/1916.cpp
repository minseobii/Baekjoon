#include <iostream>
#include <climits>
using namespace std;
int N,M;
int startnum;
int endnum;

int arr[1001][1001] = {0,};
int arr_n[1001][1001] = {0,};
int dis[1001] = {0,};
int visit[1001] = {0,};

int SmallPath() {
    int num = INT_MAX;
    int idx = -1;
    for (int i=1;i<=N;i++) {
        if (!visit[i]) {
            if (num > dis[i]) {
                num = dis[i];
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> M;
    for (int i=0;i<M;i++) {
        int s,e,c;
        cin >> s >> e >> c;
        if (arr_n[s][e] == 0) {
            arr[s][e] = c;
            arr_n[s][e] = 1;
        }
        else {
            arr[s][e] = min(arr[s][e], c);
        }
    }
    cin >> startnum >> endnum;

    for (int i=1;i<=N;i++) {
        if (startnum != i && arr_n[startnum][i]) {
            dis[i] = arr[startnum][i];
        }
        else {
            dis[i] = INT_MAX;
        }
    }
    dis[startnum] = 0;
    visit[startnum] = 1;
    
    for (int i=0;i<N-1;i++) {
        int NodeIdx = SmallPath();
        visit[NodeIdx] = 1;
        for (int j=1;j<=N;j++) {
            if (!visit[j] && arr_n[NodeIdx][j]) {
                if (dis[j] > dis[NodeIdx] + arr[NodeIdx][j]) {
                    dis[j] = dis[NodeIdx] + arr[NodeIdx][j];
                }
            }
        }
    }
    cout << dis[endnum] << endl;
    return 0;
}
