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
int N,ans;
vector<pair<int,int>> v;

struct DATE {
    int month, day;
};

int cmp_date(DATE a, DATE b){
    if (a.month == b.month) {
        if (a.day > b.day) return 1;
        else if (a.day < b.day) return -1;
        else return 0;
    }

    if (a.month > b.month) return 1;
    else if (a.month < b.month) return -1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin().v.end());

    DATE start = {0,0}; 
    DATE end = {3,1};
    DATE Max = {0,0};
    for (pair<int,int> flower : v) {
        DATE date = {flower.first, flower.second};
        
        if (cmp(date,end) >= 0) {
            if (Max.month == 0 && Max.day == 0) {
                cout << 0 << '\n';
                return 0;
            }
            
        }


    }

    cout << ans << '\n';
    return 0;
}
