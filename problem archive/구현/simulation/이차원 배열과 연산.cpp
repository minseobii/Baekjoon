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
int r,c,k,ans,arr[100][100];
int R = 3;
int C = 3;

int cal_R() {
    int Max = 0;
    for (int i=0;i<R;i++) {
        int count = 0;
        pair<int,int> temp[101];
        for (int j=1;j<101;j++) {
            temp[j].first = 101;
            temp[j].second = j;
        }
        for (int k=0;k<100;k++) {
            if (arr[i][k] == 0) continue;
            if (temp[arr[i][k]].first == 101) {
                temp[arr[i][k]].first = 0;
                count += 2;
            }
            temp[arr[i][k]].first++;
        }
        count = min(100, count);

        sort(temp+1,temp+101);
        for (int j=0;j<100;j+=2) {
            if (j <= count && temp[j/2+1].first != 101) {
                arr[i][j] = temp[j/2+1].second;
                arr[i][j+1] = temp[j/2+1].first;
            }
            else {
                arr[i][j] = 0;
                arr[i][j+1] = 0;
            }
        }

        Max = max(Max, count);
    }

    return Max;
}

int cal_C() {
    int Max = 0;
    for (int i=0;i<C;i++) {
        int count = 0;
        pair<int,int> temp[101];
        for (int j=1;j<101;j++) {
            temp[j].first = 101;
            temp[j].second = j;
        }
        for (int k=0;k<100;k++) {
            if (arr[k][i] == 0) continue;
            if (temp[arr[k][i]].first == 101) {
                temp[arr[k][i]].first = 0;
                count += 2;
            }
            temp[arr[k][i]].first++;
        }
        count = min(100, count);

        sort(temp+1,temp+101);
        for (int j=0;j<100;j+=2) {
            if (j <= count && temp[j/2+1].first != 101) {
                arr[j][i] = temp[j/2+1].second;
                arr[j+1][i] = temp[j/2+1].first;
            }
            else {
                arr[j][i] = 0;
                arr[j+1][i] = 0;
            }
        }

        Max = max(Max, count);
    }

    return Max;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c >> k;
    r -= 1;
    c -= 1;
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cin >> arr[i][j];
        } 
    }

    while(ans <= 100) {
        if (arr[r][c] == k) break;

        if (R >= C) {
            C = cal_R();
        }
        else {
            R = cal_C();
        }
        ans++;
        // for (int i=0;i<R;i++) {
        //   for(int j=0;j<C;j++) {
        //     cout << arr[i][j] << ' ';
        //   }
        //   cout << endl;
        // }
        // cout << endl;
    }

    if (ans > 100) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}
