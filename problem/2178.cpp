#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int T;

int dx[8]={2,2,-2,-2,1,1,-1,-1};
int dy[8]={1,-1,1,-1,2,-2,2,-2};

int knight() {
        int visit[301][301] = {0,};
        int I;
        queue<tuple<int,int,int>> q;
        int ans=0;
        
        cin >> I;

        int a,b;
        cin >> a >> b;
        q.push(tuple<int,int,int>(a,b,0));

        int A,B;
        cin >> A >> B;
        
        if (a==A && b == B) {
          ans = 0;
          q.pop();
        }

        while(!q.empty()) {
            int i = get<0>(q.front());
            int j = get<1>(q.front());
            int depth = get<2>(q.front());
            q.pop();   

            for (int k=0;k<8;k++) {
                int new_i = i + dx[k];
                int new_j = j + dy[k];
                
                if (new_i == A && new_j == B) {
                    ans = depth+1;
                    break;
                }

                if (new_i < 0 || new_j < 0 || new_i+1 > I || new_j+1 > I || visit[new_i][new_j] == 1) {
                    
                    continue;
                }
                q.push(tuple<int,int,int>(new_i,new_j,depth+1));
                visit[new_i][new_j] = 1;

            }
            if (ans) {
                break;
            }

        }
        cout << ans << endl;
        return 0;
}

int main() {
    cin >> T;
    
    for (int t=0;t<T;t++) {
        knight();
    }

    return 0;
}
