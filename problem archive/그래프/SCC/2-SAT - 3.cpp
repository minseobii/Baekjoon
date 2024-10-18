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
int N,M,rev[20001],A[20001];
int id = 1;
bool ans = true;
bool visit[20001];
vector<int> v[20001];
vector<vector<int>> SCC;
stack<int> st;

int dfs(int x) {
    A[x] = id++;
    int ret = A[x];
    st.push(x);
    for (int k : v[x]) {
        if (A[k] == 0) {
            ret = min(ret, dfs(k));
        }
        else if (visit[k] == 0) {
            ret = min(ret, A[k]);
        }
    }

    if (ret == A[x]) {
        int k;
        int c = 0;
        vector<int> temp;
        while(1) {
            c++;
            k = st.top();
            st.pop();
            visit[k] = true;
            temp.push_back(k);
            if (k == x) break;
        }
        SCC.push_back(temp);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<20001;i++) {
        if (i <= 10000) rev[i] = i+10000;
        else rev[i] = i-10000;
    }
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        if (a < 0) a = -a + 10000;
        if (b < 0) b = -b + 10000;
        v[rev[a]].push_back(b);
        v[rev[b]].push_back(a);
    }

    for (int i=1;i<=N;i++) {
        if (A[i]) continue;
        dfs(i);
    }
    for (vector<int> i : SCC) {
        map<int,bool> m;
        for (int j : i) {
            if (m[rev[j]]) {
                ans = false;
                break;
            }   
            m[j] = true;
        }
    }

    cout << ans << '\n';

    return 0;
}
