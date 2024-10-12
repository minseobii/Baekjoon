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
int V,E,id,root,DST[10001],init[10001];
bool visit[10001];
vector<int> Edge[10001];
vector<int> Alticulation_point; // 단절점 

int dfs(int x, bool type) {
    visit[x] = true;
    DST[x] = id++;
    int ret = DST[x];
    int child = 0;
    for (int nx : Edge[x]) {
        if (visit[nx]) {
            ret = min(ret, DST[nx]);
            continue;
        }
        child++;
        int temp = dfs(nx, true);
        if (temp == DST[x] && type) {
            Alticulation_point.push_back(x);
            type = false;
        }
        ret = min(ret, temp);
    }
    if (root == x && child > 1) Alticulation_point.push_back(x);
    DST[x] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i=0;i<E;i++) {
        int a,b;
        cin >> a >> b;
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }

    for (int i=1;i<=V;i++) {
        if (visit[i]) continue;
        root = i;
        dfs(i,false);
    }

    sort(Alticulation_point.begin(),Alticulation_point.end());
    cout << Alticulation_point.size() << '\n';
    for (int x : Alticulation_point) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
