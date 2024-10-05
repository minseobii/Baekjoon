#include <iostream>
#include <queue>
using namespace std;
int R,C,M,ans;

int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,1,-1};
int reverse_d[5] = {0,2,1,4,3};

struct SHARK {
    int r,c,s,d,z;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;

    queue<SHARK> q;
    int fishing = 101; 

    for (int i=0;i<M;i++) {
        int r,c,s,d,z;
        cin >> r >> c >> s >> d >> z;
        if ((d == 1 || d == 2) && (R > 1) && (s > ((2*R) - 2))) s = s % ((2*R) - 2);
        else if ((d == 3 || d == 4) && (C > 1) && (s > ((2*C) - 2))) s = s % ((2*C) - 2);
        SHARK shark = {r,c,s,d,z};
        q.push(shark);
        if (c == 1) fishing = min(fishing, r);
    }

    for (int i=1;i<=C;i++) {
        int killshark = 0;
        int fishing_now = fishing;
        fishing = 101;

        int arr[105][105] = {0,};
        queue<SHARK> tempq;

        for (int j=0;j<M;j++) {
            SHARK shark = q.front();
            q.pop();

            if (shark.r == fishing_now && shark.c == i) {
                ans += shark.z;
                killshark++;
            }
            else {
                int nr = shark.r;
                int nc = shark.c;

                for (int k=0;k<shark.s;k++) {
                    nr += dr[shark.d];
                    nc += dc[shark.d];

                    if (nr == 0 || nr == R+1 || nc == 0 || nc == C+1) {
                        shark.d = reverse_d[shark.d];
                        nr += dr[shark.d] + dr[shark.d];
                        nc += dc[shark.d] + dc[shark.d];
                    }
                }

                SHARK new_shark = {nr,nc,shark.s,shark.d,shark.z};
                if (arr[nr][nc] < new_shark.z) {
                    arr[nr][nc] = new_shark.z;
                    tempq.push(new_shark);
                }
                else {
                    killshark++;
                }
            }
        }
        while(!tempq.empty()) {
            SHARK temp = tempq.front();
            if (temp.z == arr[temp.r][temp.c]) {
                q.push(temp);
                if (temp.c == i+1) fishing = min(fishing,temp.r);
            }
            else killshark++;
            tempq.pop();
        }

        if (killshark) M -= killshark;

    }

    cout << ans << endl;
    return 0;
}
