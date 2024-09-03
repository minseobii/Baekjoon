#include <iostream>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
int T;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        char arr[100][100] = {0,};
        bool visit[100][100] = {0,};
        bool key[26] = {0,};
        bool change = true;

        int h,w;
        int ans = 0;
        cin >> h >> w;

        queue<pair<int,int>> q;

        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                cin >> arr[i][j];
                if (i!=0 && j!=0 && i!=h-1 && j!=w-1) continue;
                if (arr[i][j] == '*') continue;
                visit[i][j] = true;
                q.push({i,j});
            }
        }

        string s;
        cin >> s;
        for (int i=0;i<s.length();i++) {
            if (s[i] == '0') break;
            key[s[i]-'a'] = true;
        }

        while(change == true) {
            vector<pair<int,int>> ClosedDoor;
            change = false;
            while(!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                if (islower(arr[x][y])) key[arr[x][y]-'a'] = true;
                else if (isupper(arr[x][y])) {
                    if (key[arr[x][y]-'A'] == false) {
                        ClosedDoor.push_back({x,y});
                        q.pop();
                        continue;
                    }
                }
                else if (arr[x][y] == '$') ans++;

                q.pop();
                change = true;

                for (int k=0;k<4;k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (arr[nx][ny] == '*' || visit[nx][ny] == true || nx<0 || ny<0 || nx >= h || ny >= w) continue;

                    visit[nx][ny] = true;
                    q.push({nx,ny});
                }
            }

            for (int v=0;v<ClosedDoor.size();v++) {
                q.push({ClosedDoor[v].first,ClosedDoor[v].second});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
