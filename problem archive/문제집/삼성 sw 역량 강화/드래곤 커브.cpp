#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans,arr[101][101];
vector<pair<int,int>> v[11];

void init() {
    v[0].push_back({0,0});
    v[0].push_back({1,0});
    for (int k=1;k<=10;k++) {
        pair<int,int> O = {v[k-1].back().first,v[k-1].back().second};
        for (pair<int,int> prev : v[k-1]) {
            v[k].push_back(prev);
        }
        for (int i=v[k-1].size()-2;i>=0;i--) {
            int nx = -v[k-1][i].second + O.second + O.first;
            int ny = v[k-1][i].first - O.first + O.second;
            v[k].push_back({nx,ny});
        }
    }
}

void cal(int a, int b, int d, int g) {
    if (d == 0) {
        for (pair<int,int> k : v[g]) {
            int nx = k.first + a;
            int ny = k.second + b;
            if (nx<0||ny<0||nx>100||ny>100) continue;
            arr[ny][nx] = 1;
        }
    }
    else if (d == 1) {
        for (pair<int,int> k : v[g]) {
            int nx = k.second + a;
            int ny = -k.first + b;
            if (nx<0||ny<0||nx>100||ny>100) continue;
            arr[ny][nx] = 1;
        }
    }
    else if (d == 2) {
        for (pair<int,int> k : v[g]) {
            int nx = -k.first + a;
            int ny = -k.second + b;
            if (nx<0||ny<0||nx>100||ny>100) continue;
            arr[ny][nx] = 1;
        }
    }
    else if (d == 3) {
        for (pair<int,int> k : v[g]) {
            int nx = -k.second + a;
            int ny = k.first + b;
            if (nx<0||ny<0||nx>100||ny>100) continue;
            arr[ny][nx] = 1;
        }
    }
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    init();
    for (int i=0;i<N;i++) {
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        cal(x,y,d,g);
    }

    for (int i=0;i<100;i++) {
        for (int j=0;j<100;j++) {
            if (arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
