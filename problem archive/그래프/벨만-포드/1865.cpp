#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;
int TC;
int ans;

struct EDGE {
    int s,e,t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> TC;
    while(TC--) {
        int N,M,W;
        cin >> N >> M >> W;
        vector<EDGE> Edge;

        for (int i=0;i<M;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            EDGE edge1;
            edge1.s = a;
            edge1.e = b;
            edge1.t = c;
            Edge.push_back(edge1);
            EDGE edge2;
            edge2.s = b;
            edge2.e = a;
            edge2.t = c;
            Edge.push_back(edge2);
        }

        for (int i=0;i<W;i++) {
            int a,b,c;
            cin >> a >> b >> c;
            EDGE edge;
            edge.s = a;
            edge.e = b;
            edge.t = -c;
            Edge.push_back(edge);
        }

        int Time[N+1] = {0,};
        int find = 0;
        for (int i=1;i<=N;i++) {
            for (int j=0;j<Edge.size();j++) {
                int s = Edge[j].s;
                int e = Edge[j].e;
                int t = Edge[j].t;
                if (Time[e] > Time[s] + t) {
                    Time[e] = Time[s] + t;
                    if (i == N) {
                        find = 1;
                        break;
                    }
                }
            }
        }
        if (find) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}
