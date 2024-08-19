#include <iostream>
#include <vector>
using namespace std;
int N,M,ans;
int end[1001];
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int m,k,s,e;
        cin >> m;
        for (int j=0;j<m;j++) {
            cin >> k;
            if (j == 0) s=k;
            else {
                v[s].push_back(k);
                s=k;
                end[k]++;
            }
        }
    }
    for (int i=0;i)
    cout << ans << endl;
    return 0;
}
