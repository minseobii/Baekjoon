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
int N,ans,arr[20][20];
map<int,bool> m[405];

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int n=0;n<N*N;n++) {
        int a,l1,l2,l3,l4;
        cin >> a >> l1 >> l2 >> l3 >> l4;
        m[a][l1] = true;
        m[a][l2] = true;
        m[a][l3] = true;
        m[a][l4] = true;

        int like = -1;
        int empty = -1;
        pair<int,int> point = {0,0};

        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                if (arr[i][j]) continue;

                int temp_like = 0;                
                int temp_empty = 0;
                for (int k=0;k<4;k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx<0 || ny<0 || nx>=N || ny>=N) continue;

                    if (arr[nx][ny] == 0) temp_empty++;
                    else if (m[a][arr[nx][ny]]) temp_like++;
                }

                if (like == temp_like) {
                    if (empty == temp_empty) {
                        if (point.first == i) {
                            if (point.second < j) continue;
                        }
                        else if (point.first < i) continue;
                    }   
                    else if (empty > temp_empty) continue;
                }
                else if (like > temp_like) continue; 
                like = temp_like;
                empty = temp_empty;
                point = {i,j};
            }
        }

        arr[point.first][point.second] = a;
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int temp_ans = 0;
            for (int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx<0 || ny<0 || nx>=N || ny>=N) continue;
                if (m[arr[i][j]][arr[nx][ny]]) {
                    if (temp_ans == 0) temp_ans = 1;
                    else temp_ans *= 10;
                }
            }

            ans += temp_ans;
        }
    }

    cout << ans << '\n';
    return 0;
}
