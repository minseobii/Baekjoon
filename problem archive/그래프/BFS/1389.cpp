#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int ans=0;
int minnum =0;

struct PAIR{
    int a, depth;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    vector<int> v[N+1];
    
    for (int i=0;i<M;i++) {
        int first;
        int second;
        cin >> first >> second;
        v[first].push_back(second);
        v[second].push_back(first);
    }

    for (int i=1;i<N+1;i++) {
        int num = 0;
        int visit[N+1] = {0,};
        visit[i] = 1;


        PAIR pair = {i, 0};
        queue<PAIR> q;          
        q.push(pair);

        while (!q.empty()) {
            int a = q.front().a;
            int depth = q.front().depth;
            q.pop();

            for (int j=0;j<v[a].size();j++) {
                if (visit[v[a][j]] == 0) {
                    num += depth+1;
                    visit[v[a][j]] = 1;
                    PAIR NewPair = {v[a][j], depth+1};
                    q.push(NewPair);
                }
            }
        }

        if (i == 1) {
            ans = i;
            minnum = num;
        }   
        else if (minnum == num) {
            ans = min(ans, i);
        }
        else {
            if (minnum > num) {
                minnum = num;
                ans = i;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
