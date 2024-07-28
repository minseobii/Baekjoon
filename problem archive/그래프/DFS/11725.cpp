#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
int N;
unordered_map<int, vector<int>> m;
int visited[100001] = {0,};
int ans[100001] = {0,};

void DFS(int x) {
    visited[x] = 1;
    if (m.find(x) == m.end()) {
        return;
    }

    for (int i=0;i<m[x].size();i++) {
        if (!visited[m[x][i]]) {
            ans[m[x][i]] = x;
            DFS(m[x][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N-1;i++) {
        int Node1, Node2;
        cin >> Node1 >> Node2;
        m[Node1].push_back(Node2);
        m[Node2].push_back(Node1);
    }
    DFS(1);
    for (int i=2;i<=N;i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
