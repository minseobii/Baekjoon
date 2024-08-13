#include <iostream>
#include <vector>
using namespace std;
int N,R,Q;
vector<int> v[100001];
bool visit[100001];
int ans[100001];

int FindQ(int root) {
    visit[root] = true;
    int Query = 1;
    for (int i=0;i<v[root].size();i++) {
        if (visit[v[root][i]] == 0) {
            Query += FindQ(v[root][i]);
        }
    }
    ans[root] = Query;
    return Query;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> R >> Q;
    for (int i=0;i<N-1;i++) {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    FindQ(R);

    for (int i=0;i<Q;i++) {
        int q;
        cin >> q;
        cout << ans[q] << '\n';
    }
    
    return 0;
}
