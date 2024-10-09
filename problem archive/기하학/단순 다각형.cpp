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
int C,N;

struct POINT {
    int x,y;
};

POINT ori;

int ccw(POINT o, POINT a, POINT b) {
    return ((a.x-o.x) * (b.y-o.y)) - ((b.x-o.x) * (a.y-o.y));
}

bool cmp(pair<POINT,int> A, pair<POINT,int> B) {
    POINT a = A.first;
    POINT b = B.first;
    int ccw_val = ccw(ori, a, b);
    if (ccw_val > 0) return true;
    else if (ccw_val < 0) return false;
    else {
        if (a.x == b.x) return a.y < b.y;
        else return a.x < b.x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C;
    while(C--) {
        cin >> N;
        vector<pair<POINT,int>> tangent;
        ori.x = 10001;
        ori.y = 10001;
        int idx;
        for (int i=0;i<N;i++) {
            int x,y;
            cin >> x >> y;
            POINT p = {x,y};
            tangent.push_back({p, i});

            if (ori.x > p.x) {
                ori.x = p.x;
                ori.y = p.y;
                idx = i;
            }
            else if (ori.x == p.x && ori.y > p.y) {
                ori.x = p.x;
                ori.y = p.y;
                idx = i;
            }
        }
        swap(tangent[0], tangent[idx]);
        sort(tangent.begin()+1,tangent.end(),cmp);

        int pt = N-1;
        while(ccw(tangent[0].first, tangent[pt].first, tangent[pt-1].first) == 0) {
            pt--;
        }
        reverse(tangent.begin()+pt, tangent.end());

        for (int i=0;i<N;i++) {
            cout << tangent[i].second <<' ';
        }
        cout << '\n';
    }
    return 0;
}
