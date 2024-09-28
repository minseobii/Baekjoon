#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,M;
int parent[100001][18];
int level[100001];
vector<int> v[100001];

void init(int x, int p, int l) {
    parent[x][0] = p;
    level[x] = l;

    for (int k=1;k<18;k++) {    
        parent[x][k] = parent[parent[x][k-1]][k-1];
    } 

    for (int i=0;i<v[x].size();i++) {
        int nx = v[x][i];
        if (nx == p) continue;
        init(nx,x,l+1);
    }
}

int find_ancsetor(int a, int b) {
    if (level[a] < level[b]) swap(a,b);
    if (level[a] != level[b]) {
        for (int k=17;k>=0;k--) {
            if (level[parent[a][k]] >= level[b]) a = parent[a][k];  
        }
    }

    if (a == b) return a;   

    int ret = a;
    for (int k=17;k>=0;k--) {
        if (parent[a][k] != parent[b][k]) {
            a = parent[a][k];
            b = parent[b][k];
        }
        ret = parent[a][k];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    init(1,0,1);

    cin >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        cout << find_ancsetor(a,b) << '\n';
    }
    return 0;
}
