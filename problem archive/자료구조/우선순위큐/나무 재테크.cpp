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
int N,M,K,ans,A[10][10];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct AREA {
    int food;
    priority_queue<int, vector<int>, greater<int>> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    AREA area[10][10];
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            area[i][j].food = 5;
            cin >> A[i][j];
        }
    }

    for (int i=0;i<M;i++) {
        int x,y,c;
        cin >> x >> y >> c;
        area[x-1][y-1].tree.push(c);
    }


    for (int i=0;i<K;i++) {
        int growtree[10][10] = {0,};
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                queue<int> temp;
                int addfood = 0;
                while(!area[i][j].tree.empty()) {
                    if (area[i][j].food >= area[i][j].tree.top()) {
                        area[i][j].food -= area[i][j].tree.top();
                        temp.push(area[i][j].tree.top() + 1);
                        if ((area[i][j].tree.top() + 1) % 5 == 0) {
                            growtree[i][j] += 1;
                        }
                    } 
                    else {
                        addfood += area[i][j].tree.top()/2;
                    }
                    area[i][j].tree.pop();
                }

                while(!temp.empty()) {
                    area[i][j].tree.push(temp.front());
                    temp.pop();
                }
                area[i][j].food += addfood;
            }
        }

        for (int i=0;i<N;i++) { // 가을, 겨울 
            for (int j=0;j<N;j++) {
                area[i][j].food += A[i][j];
                if (growtree[i][j] == 0) continue;
                for (int d=0;d<8;d++) {
                    int nr = i + dr[d];
                    int nc = j + dc[d];
                    if (nr<0 || nc<0 || nr>=N || nc>= N) continue;
                    for (int k=0;k<growtree[i][j];k++) {
                        area[nr][nc].tree.push(1);
                    }
                }
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            ans += area[i][j].tree.size();
        }
    }

    cout << ans << '\n';
    return 0;
}
