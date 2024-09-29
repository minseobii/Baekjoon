#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 20000
using namespace std;
int N,M;
float ans = INF;
float two = 2;
int maxDis[201][201];  
int Dis[201][201];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            Dis[i][j] = INF;
        }
    }

    for(int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if (Dis[a][b] > c) Dis[a][b] = c;
        if (Dis[b][a] > c) Dis[b][a] = c;
        if (maxDis[a][b] < c) maxDis[a][b] = c;
        if (maxDis[b][a] < c) maxDis[b][a] = c;
    }

    for (int k=1;k<=N;k++) {
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (i == j) {
                    Dis[i][j] = 0;
                    continue;
                }
                Dis[i][j] = min(Dis[i][j], Dis[i][k] + Dis[k][j]);
            }
        }
    }

    for (int k=1;k<=N;k++) {
        float temp = 0;
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=N;j++) {
                if (maxDis[i][j] == 0) continue;
                float u = Dis[k][i];
                float v = Dis[k][j];
                if (u < v) swap(u,v);

                if (maxDis[i][j] == Dis[i][j]) temp = max(temp, u); // v에서 u로 가는 도중에 다 타는 경우
                else temp = max(temp, (maxDis[i][j]-(u-v))/two + u); // 남은 부분이 있어 중간에서 타는 경우
            }
        }
        ans = min(ans, temp);
    }       
    cout << fixed;
    cout.precision(1);
    cout << ans << '\n';
    return 0;
}
