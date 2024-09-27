#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,L,ans;
int arr[100][100];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    ans = 2 * N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    for (int i=0;i<N;i++) {
        vector<pair<int,int>> v;
        int idx = 0;
        v.push_back({arr[i][0],1});
        for (int j=1;j<N;j++) {
            if (v[idx].first == arr[i][j]) v[idx].second++;
            else {
                v.push_back({arr[i][j],1});
                idx++;
            }
        }

        for (int k=1;k<v.size();k++) {
            if (v[k-1].first == v[k].first+1) {
                if (v[k].second >= L) {
                    v[k].second -= L;
                }
                else {
                    ans--;
                    break;
                }
            }
            else if (v[k-1].first+1 == v[k].first) {
                if (v[k-1].second >= L) {
                    v[k-1].second -= L;
                }
                else {
                    ans--;
                    break;
                }
            }
            else {
                ans--;
                break;
            }
        }
    }

    for (int i=0;i<N;i++) {
        vector<pair<int,int>> v;
        int idx = 0;
        v.push_back({arr[0][i],1});
        for (int j=1;j<N;j++) {
            if (v[idx].first == arr[j][i]) v[idx].second++;
            else {
                v.push_back({arr[j][i],1});
                idx++;
            }
        }

        for (int k=1;k<v.size();k++) {
            if (v[k-1].first == v[k].first+1) {
                if (v[k].second >= L) {
                    v[k].second -= L;
                }
                else {
                    ans--;
                    break;
                }
            }
            else if (v[k-1].first+1 == v[k].first) {
                if (v[k-1].second >= L) {
                    v[k-1].second -= L;
                }
                else {
                    ans--;
                    break;
                }
            }
            else {
                ans--;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
