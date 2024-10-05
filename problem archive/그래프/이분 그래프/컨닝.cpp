#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define MAX 6400
using namespace std;
int C,N,M,ans;
bool arr[80][80];
bool visit[MAX];
int A[MAX];
vector<int> v[MAX];
int dir[6][2] = {{-1,-1},{0,-1},{1,-1},{-1,1},{0,1},{1,1}};

void init() {
    cin >> N >> M;
    ans = N * M;
    for (int i=0;i<80;i++) {
        for (int j=0;j<80;j++) {
            arr[i][j] = false;
            A[80*i+j] = -1;
            v[80*i+j].clear();
        }
    }
}

bool dfs(int id) {
    visit[id] = true;
    for (int nid : v[id]) {
        if (A[nid] == -1 || !visit[A[nid]] && dfs(A[nid])) {
            A[id] = nid;
            A[nid] = id;    
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C;
    while(C--) {
        init();

        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                char c;
                cin >> c;
                if (c == 'x') ans -= 1;
                else arr[i][j] = true;
            }
        }

        for (int j=0;j<M;j+=2) {
            for (int i=0;i<N;i++) {
                if (arr[i][j] == false) continue;
                int id = i*80+j;
                for (int k = 0;k<6;k++) {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if (ni<0 || nj<0 || ni>=N || nj>=M || arr[ni][nj] == false) continue;
                    v[id].push_back(ni*80+nj);
                }
            }
        }

        for (int j=0;j<M;j+=2) {
            for (int i=0;i<N;i++) {
                int id = i*80+j;
                if (A[id] == -1) {
                    fill(visit,visit+MAX,false);
                    if (dfs(id)) ans -= 1;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
