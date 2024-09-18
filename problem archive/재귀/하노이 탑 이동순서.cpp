#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans;
vector<pair<int,int>> v;

void print(int a, int b) {
    v.push_back({a,b});
    ans++;
}

void cal(int start, int end, int level) {
    int mid;
    for (int i=1;i<=3;i++) {
        if (i == start || i == end) continue;
        mid = i;
    }

    if (level == 1) {
        print(1,3);
    }
    else if (level == 2) {   
        print(start, mid);
        print(start, end);
        print(mid, end);
    }
    else {
        cal(start, mid, level-1);
        print(start, end);
        cal(mid, end, level-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cal(1,3,N);

    cout << ans << '\n';
    for (int i=0;i<v.size();i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}
