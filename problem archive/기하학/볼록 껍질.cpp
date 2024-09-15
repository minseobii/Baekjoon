#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
int N,ans;

struct POINT {
    int x,y;
};

vector<POINT> arr;
vector<POINT> tangent;
stack<POINT> st;

POINT Min = {40001,40001};

bool cmp(POINT a, POINT b) {
  long long ll = 1;
    if (ll*a.y*b.x != ll*a.x*b.y) return ll*a.y*b.x < ll*a.x*b.y;
    else if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

int ccw(POINT v1, POINT v2) {
    long long ll = 1;
    long long value = (ll*v1.x*v2.y)-(ll*v2.x*v1.y);
    if (value > 0) return 1;
    else if (value < 0) return -1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        POINT p;
        cin >> p.x >> p.y;
        arr.push_back(p);
        if (p.x < Min.x) {
            Min.x = p.x;
            Min.y = p.y;
        }
        else if (p.x == Min.x && p.y < Min.y) {
            Min.x = p.x;
            Min.y = p.y;
        } 
    }

    for (int i=0;i<N;i++) {
        POINT p = {arr[i].x - Min.x, arr[i].y - Min.y};
        tangent.push_back(p);
    }

    for (int i=0;i<N;i++) {
        if (tangent[i].x == 0 && tangent[i].y == 0) {
            swap(tangent[i],tangent[0]);
        }
    }

    sort(tangent.begin()+1,tangent.end(),cmp);

    // for (int i=0;i<N;i++) {
    //     cout << tangent[i].x << ' ' << tangent[i].y << endl;
    // }
    
    int idx = 2;
    tangent[N] = tangent[0];
    st.push(tangent[0]);
    st.push(tangent[1]);
    while(idx <= N) {
        while(st.size() >= 2) {
            POINT mid = st.top();
            st.pop();
            POINT start = st.top();
            POINT end = tangent[idx];
            POINT v1 = {mid.x-start.x,mid.y-start.y};
            POINT v2 = {end.x-mid.x,end.y-mid.y};
            
            //cout << start.x << ' '<< start.y <<  "  ||  " << mid.x << ' ' << mid.y << endl; 

            int ret = ccw(v1,v2);
            if (ret > 0) {
                st.push(mid);
                break;
            }
        }
        if (idx == N) break;
        st.push(tangent[idx++]);
    }

    // while(!st.empty()) {
    //   cout << st.top().x << ' ' << st.top().y << endl;
    //   st.pop();
    // }

    cout << st.size() << '\n';
    return 0;
}
