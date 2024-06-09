#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int T,I;
int ans=0;

int dy[8]={2,2,-2,-2,1,1,-1,-1};
int dx[8]={1,-1,1,-1,2,-2,2,-2};
queue<tuple<int,int,int>> q;

int main() {
    cin >> T;
    
    for (int t=0;t<T;t++) {
        int visit[301][301];
        cin >> I;

        int a,b;
        cin >> a >> b;
        q.push(tuple<int,int,int>(a,b,0));

        int A,B;
        cin >> A >> B;

        while(!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int depth = get<2>(q.front());
            q.pop();

            for (int i=0;i<8;i++) {
                int new_i = i + dx[i];
                int new_j = j + dy[i];

                if (new_i < 0 || new_j < 0 || new_i+1 > I || new_j+1 > I || visit[new_i][new_j] == 1) {
                    continue;
                }
                q.push(tuple<int,int,int>(new_i,new_j,depth+1));
                visit[new_i][new_j] = 1;

                if (new_i == A && new_j == B) {
                    ans = depth+1;
                    break;
                }
            }
            if (ans) {
                break;
            }

        }
        cout << ans << endl;
        //값 초기화
        ans = 0;
    }

    return 0;
}
