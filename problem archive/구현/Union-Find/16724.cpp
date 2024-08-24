#include <iostream>
#include <map>
using namespace std;
int R,C,ans;
char arr[1000][1000];
pair<int,int> parent[1000][1000];
bool root[1000][1000];

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

pair<int,int> find(int a, int b) {
    if (a == parent[a][b].first && b == parent[a][b].second) return {a,b};
    pair<int,int> p = find(parent[a][b].first, parent[a][b].second);
    return {p.first,p.second};
}

void merge(int u1, int u2, int v1, int v2) {
    pair<int,int> u;
    pair<int,int> v;
    u = find(u1,u2);
    v = find(v1,v2);

    if (u == v) return;
    parent[v.first][v.second] = {u.first,u.second};
    root[u.first][u.second] = true;
    root[v.first][v.second] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;

    map<char,int> m;
    m['U'] = 0;
    m['D'] = 1;
    m['L'] = 2;
    m['R'] = 3;

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> arr[i][j];
            parent[i][j] = {i,j};
        }
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            merge(i+dr[m[arr[i][j]]],j+dc[m[arr[i][j]]],i,j);
        }
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (root[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
