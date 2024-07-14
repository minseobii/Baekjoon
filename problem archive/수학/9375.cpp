#include <iostream>
#include <vector>
using namespace std;
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        int n;
        vector<pair<string,int>> v;
        cin >> n;

        for (int i=0;i<n;i++) {
            int find = 0;
            string temp;
            string clothes;
            cin >> temp >> clothes;
            for (int j=0;j<v.size();j++) {
                if (v[j].first.compare(clothes) == 0) {
                    v[j].second++;
                    find = 1;
                }
            }
            if (find == 0) {
                v.push_back({clothes, 2});
            }
        }

        int ans = 1;
        for (int i=0;i<v.size();i++) {
            ans *= v[i].second;
        }

        cout << ans-1 << '\n';
    }
    return 0;
}
