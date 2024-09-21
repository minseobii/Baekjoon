#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int V,E;
int id = 1;
int parent[10001];
bool visit[10001];

stack<int> st;
vector<int> v[10001];
vector<vector<int>> SCC;

int DFS(int x) {
    int ret = id++; // id가 작다는 것은 이전에 거쳐왔던 노드라는 것 
    parent[x] = ret;
    st.push(x);
    for (int i=0;i<v[x].size();i++) {
        int next = v[x][i];
        if (parent[next] == 0) {
            ret = min(ret, DFS(next));
        }
        else if (visit[next] == 0) {
            ret = min(ret, parent[next]);
        }
        // ret을 작은 것을 선택 -> 점점 dfs를 빠져나올 수록 작아짐 -> parent[x] 와 ret이 같은 값에 도달
    }

    if (parent[x] == ret) { // 같은 SCC가 아니라면 이전 DFS에서 이미 다른 SCC로 stack에서 pop됨
        vector<int> temp;
        int k;
        do {
            k = st.top();
            temp.push_back(k);
            visit[k] = true;
            st.pop();
        } while(k != x);
        sort(temp.begin(),temp.end());
        temp.push_back(-1);

        SCC.push_back(temp);
    }

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
        v[a].push_back(b);
    }

    for (int i=1;i<=V;i++) {
        if (parent[i]) continue;
        DFS(i);
    }

    sort(SCC.begin(),SCC.end());
    cout << SCC.size() << '\n';
    for (int i=0;i<SCC.size();i++) {
        for (int j=0;j<SCC[i].size();j++) {
            cout << SCC[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
