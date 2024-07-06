#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int ans=0;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<N;i++) {
        int temp1;
        int temp2;
        cin >> temp1 >> temp2;

        v.push_back({temp2, temp1});
    }

    sort(v.begin(),v.end());

    int now = v[0].first;
    ans++;


    for (int i=1;i<N+1;i++) {
        if (v[i].second >= now) {
            now = v[i].first;
            ans++;
        }
    }

    cout << ans << endl; 
    return 0;
}
