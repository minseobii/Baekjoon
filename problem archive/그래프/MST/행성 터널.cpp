#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,e;
long long ans;

int input[3][100000];
pair<int,int> arr[3][100001];
vector<pair<int,pair<int,int>>> Edge;

int parent[100000];
int ran[100000];

int cal_w(int a, int b) {
    int num = 2000000001;
    for (int i=0;i<3;i++) {
        num = min(num,abs(input[i][a]-input[i][b]));
    }
    return num;
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool iscycle(int u, int v) {
    if (find(u) == find(v)) return true;
    return false;
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (ran[v] > ran[u]) swap(u,v);
    else if (ran[v] == ran[u]) ran[u]++;

    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> input[0][i] >> input[1][i] >> input[2][i];
        for (int j=0;j<3;j++) {
            arr[j][i] = {input[j][i], i};
        }

        parent[i] = i;
        ran[i] = 1;
    }

    for (int i=0;i<3;i++) {
        sort(arr[i],arr[i]+N);
    }
    for (int i=0;i<3;i++) {
        arr[i][N].first = arr[i][0].first;
        arr[i][N].second = arr[i][0].second;
    }

    for (int i=0;i<3;i++) {
        for (int j=0;j<N;j++) {
            int w = cal_w(arr[i][j].second,arr[i][j+1].second);
            int s = arr[i][j].second;
            int e = arr[i][j+1].second;
            Edge.push_back({w,{s,e}});
        }
    }

    sort(Edge.begin(),Edge.end());

    for (int i=0;i<Edge.size();i++) {
        int u = Edge[i].second.first;
        int v = Edge[i].second.second;
        
        if (iscycle(u,v)) continue;

        merge(u,v);
        ans += Edge[i].first;
        e++;

        if (e == N-1) break;
    }

    cout << ans << endl;
    return 0;
}
