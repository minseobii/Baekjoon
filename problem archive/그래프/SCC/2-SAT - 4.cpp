#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 20002
using namespace std;
int N,M,id,num,value[MAX],setnum[MAX],ans[MAX/2];
bool visit[MAX];

vector<int> SCC;
vector<int> v[MAX];
stack<int> st;

int NOT(int x) {
    if (x%2) return x-1;
    return x+1;
}

int DFS(int x) {
    value[x] = ++id;
    int ret = value[x];
    st.push(x);
    for (int k : v[x]) {
        if (value[k] == 0) ret = min(ret, DFS(k));
        else if (visit[k] == 0) ret = min(ret, value[k]);
    }

    if (ret == value[x]) {
        num++;
        while(1) {
            int k = st.top();
            st.pop();

            SCC.push_back(k);
            setnum[k] = num;    
            visit[k] = true;
            if (x == k) break;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        if (a<0) a = abs(a)*2+1;
        else a = a*2;
        if (b<0) b = abs(b)*2+1;
        else b = b*2;

        v[NOT(a)].push_back(b);
        v[NOT(b)].push_back(a);
    }

    for (int i=2;i<=N*2+1;i++) {
        if (value[i] == 0) DFS(i);
    }

    for (int i=1;i<=N;i++) {
        if (setnum[i*2] == setnum[i*2+1]) {
            cout << 0 << '\n';
            return 0;
        }
    }

    fill(ans,ans+MAX/2,-1);
    for (int i=SCC.size()-1;i>=0;i--) {
        int x = SCC[i];
        if (ans[x/2] == -1) ans[x/2] = x%2 ? 1 : 0; 
    }

    cout << 1 << '\n';
    for (int i=1;i<=N;i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
