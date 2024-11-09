#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 10000
using namespace std;
int N,M,arr[50][50];
int ans = -1;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

vector<pair<int,int>> num[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
            num[arr[i][j]].push_back({i,j});
            arr[i][j] *= -1;
        }
    }

    int subarr[num[2].size()] = {0,};
    fill(subarr,subarr+M,1);

    do {
        queue<pair<pair<int,int>,int>> q;
        int dis[50][50] = {0,};

        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (arr[i][j] == 0) dis[i][j] = MAX;
                else if (arr[i][j] == -1) dis[i][j] = -1;
            }
        }

        for (int i=0;i<num[2].size();i++) {
            if (subarr[i]) {
                q.push({num[2][i],0});
                dis[num[2][i].first][num[2][i].second] = -1;
            }
            else dis[num[2][i].first][num[2][i].second] = MAX;
        }

        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();

            for (int k=0;k<4;k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx<0 || ny<0 || nx>=N || ny>= N || arr[nx][ny] == -1) continue;
                if (dis[nx][ny] > t+1) {
                    dis[nx][ny] = t+1;
                    q.push({{nx,ny},t+1});
                }
            }
        }

        int temp_ans = 0;
        int virus = 0;

        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (arr[i][j] == 0 && dis[i][j] != MAX) {
                    temp_ans = max(temp_ans, dis[i][j]);
                    virus++;
                }
            }
        }
        if (virus == num[0].size()) {
            if (ans == -1) ans = temp_ans;
            else ans = min(ans, temp_ans);
        }
    }while(prev_permutation(subarr,subarr+num[2].size()));
    
    cout << ans << '\n';
    return 0;
}
