#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 100000
using namespace std;

int T,N;
double ans;
pair<int,int> O;

vector<pair<int,int>> v;
vector<pair<int,int>> convex_hull;

void init() {
    int idx = 0;
    ans = MAX;
    O = {MAX, MAX};
    v.clear();
    convex_hull.clear();

    for (int i=0;i<N;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});

        if (y == O.second) {
            if (x < O.first) {
                O = {x,y};
                idx = i;
            }
        }
        else if (y < O.second) {
            O = {x,y};
            idx = i;
        }
    }

    v[idx] = v[0];
    v[0] = O;
}

int cross_conduct(int x1, int y1, int x2, int y2) {
    return x1*y2 - x2*y1;
}
int CCW(pair<int,int> A, pair<int,int> B, pair<int,int> C) {
    int ccw = cross_conduct(B.first-A.first,B.second-A.second,C.first-B.first,C.second-B.second);
    if (ccw > 0) return 1;
    else if (ccw == 0) return 0;
    return -1;
}

bool cmp(pair<int,int> A, pair<int,int> B) {
    int ccw = CCW(O,A,B);
    if (ccw > 0) return true;
    else if (ccw == 0) {
        if (A.first != B.first) {
            return A.first < B.first;
        }
        return A.second < B.second;
    }
    return false;
}

void find_convex_hull() {
    stack<pair<int,int>> st;
    st.push(v[0]);
    st.push(v[1]);
    for (int i=2;i<v.size();) {
        while(st.size() >= 2) {
            pair<int,int> mid = st.top();
            st.pop();
            pair<int,int> start = st.top();
            pair<int,int> end = v[i];

            if (CCW(start,mid,end) > 0) {
                st.push(mid);
                break;
            }
        }
        st.push(v[i++]);
    }

    stack<pair<int,int>> temp;
    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()) {
        convex_hull.push_back(temp.top());
        temp.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N) {
        init();
        sort(v.begin()+1,v.end(),cmp);
        find_convex_hull();

        pair<int,int> P,H;
        for (int i=0;i<convex_hull.size();i++) {
            double temp_ans = 0;
            P = convex_hull[i];
            H = convex_hull[(i+1)%convex_hull.size()];

            for (pair<int,int> A : convex_hull) {
                if ((A.first == P.first && A.second == P.second) || (A.first == H.first && A.second == H.second)) continue;
                double u = ((H.first-P.first) * (H.first-P.first)) + ((H.second-P.second) * (H.second-P.second));
                double Dis = (double)(abs(cross_conduct(H.first-P.first,H.second-P.second,A.first-H.first,A.second-H.second))) / sqrt(u);
                temp_ans = max(temp_ans, Dis);
            }

            ans = min(ans, temp_ans);
        }
        ans *= 100;
        if (ans - (long long)ans > 1e-12) {
            ans += 1;
            ans = (long long) ans;
        }
        ans /= 100;

        cout << fixed;
        cout.precision(2);
        cout << "Case " << ++T << ": " << ans << '\n';
        cin >> N;
    }
    return 0;
}
