#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
int arr[8];
int sort_arr[8];
int sub_arr[8] = {1,10,100,1000,10000,100000,1000000,10000000};
int oper[10][2];
int cost[10];
int Dis[100000000];

unordered_map<int,bool> m;

int cal(int A[]) {
    int k=0;
    for (int i=0;i<N;i++) {
        k *= 10;
        k += A[i];
    }
    return k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
        arr[i]--;
        sort_arr[i] = arr[i];
    }
    sort(sort_arr,sort_arr+N);

    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> oper[i][0] >> oper[i][1] >> cost[i];
    }

    priority_queue<pair<int,int>> q;
    int start = cal(arr);
    int end = cal(sort_arr);

    m[start] = true;
    Dis[end] = -1;
    Dis[start] = 0;
    q.push({0,start});

    while(!q.empty()) {
        int w = -q.top().first;
        int x = q.top().second;
        q.pop();

        if (Dis[x] < w) continue;

        for (int i=0;i<M;i++) {
            int nx,nw,a,b;
            a = (x / sub_arr[N - oper[i][0]]) % 10;
            b = (x / sub_arr[N - oper[i][1]]) % 10;

            nx = x - (a*sub_arr[N - oper[i][0]]) - (b*sub_arr[N - oper[i][1]]);
            nx = nx + (b*sub_arr[N - oper[i][0]]) + (a*sub_arr[N - oper[i][1]]);
            nw = cost[i];

            if (m[nx] == false) {
                m[nx] = true;
                Dis[nx] = w + nw;
                q.push({-Dis[nx],nx});
            }
            else if (Dis[nx] > w + nw) {
                Dis[nx] = w + nw;
                q.push({-Dis[nx],nx});
            }
        }
    }

    cout << Dis[end] << '\n';

    return 0;
}
