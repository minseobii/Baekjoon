    #include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 2000
using namespace std;
int N,M,id,SCC,ans,A[MAX],set[MAX];
bool finished[MAX];

vector<int> v[MAX];
stack<int> st;

int NOT(int x) {
    if (x%2 == 0) return x+1;
    return x-1;
}

void init() {
    SCC = 1;
    id = 1;
    ans = 1;
    for (int i=0;i<MAX;i++) v[i].clear();
    fill(A,A+MAX,0);
    fill(finished,finished+MAX,false);
    fill(set,set+MAX,false);
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        if (a < 0) a = abs(a)*2+1;
        else a = 2*a;
        if (b < 0) b = abs(b)*2+1;
        else b = 2*b;

        v[NOT(a)].push_back(b);
        v[NOT(b)].push_back(a);
    }
    v[NOT(2)].push_back(2);
}

int DFS(int x) {
    A[x] = id++;
    int ret = A[x];
    st.push(x);
    for (int k : v[x]) {
        if (A[k] == 0) ret = min(ret, DFS(k));
        else if (finished[k] == 0) ret = min(ret, A[k]);
    }

    if (ret == A[x]) {
        while(1) {
            int k = st.top();
            set[k] = SCC;
            finished[k] = true;
            st.pop();
            if (k == x) break;
        }
        SCC++;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> N) {
        cin >> M;
        init();
        for (int i=2;i<=2*N+1;i++) {
            if (A[i]) continue;
            DFS(i);
        }

        for (int i=1;i<=N;i++) {
            if (set[i*2] == set[i*2+1]) ans = 0;
        }

        if (ans) cout << "yes" << '\n';
        else cout << "no" << '\n';
    } 
    
    return 0;
}
