#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,ans;

vector<pair<int,pair<int,int>>> Edge;
int parent[100001];
int ran[100001];
int num;
int temp;

int find(int u) {
	if (u == parent[u]) return u;
	return find(parent[u]);
}

void merge(int u, int v, int w) {
	u = find(u);
	v = find(v);
	if (u == v) {
        return;
    }
    if (ran[u] > ran[v])  {
        int a = u;
        u = v;
        v = a;
    }
    if (ran[u] == ran[v]) {
        ran[v]++;
    }
	parent[u] = v;
    ans += w;
    temp = w;
    num++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        Edge.push_back({c,{a,b}});
    }

    sort(Edge.begin(),Edge.end());

    for (int i=1;i<=N;i++) {
        parent[i] = i;
        ran[i] = 1;
    }

    for (int i=0;i<Edge.size();i++) {
        merge(Edge[i].second.first,Edge[i].second.second,Edge[i].first);

        if (num == N-1) {
            ans -= temp;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
