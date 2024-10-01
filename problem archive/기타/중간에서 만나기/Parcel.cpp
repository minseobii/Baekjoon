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
int N,W;
bool ans;
int arr[5000];
vector<pair<int,int>> v[400001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> W >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    } 
    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        for (int j=i+1;j<N;j++) {
            int k = arr[i] + arr[j];
            if (W - k > 400000 || W-k < 0) continue;
            for (int x=0;x<v[W-k].size();x++) {
                if (v[W-k][x].first != i && v[W-k][x].first != j && v[W-k][x].second != i && v[W-k][x].second != j) {
                    ans = true;
                    break;
                }
            }
            if (ans) break;
            v[k].push_back({i,j});
        }
    }

    if (ans) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
