#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
long long ans;
int A[4000];
int B[4000];
int C[4000];
int D[4000];

vector<int> u;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            u.push_back(A[i]+B[j]);
            v.push_back(C[i]+D[j]);
        }
    }

    sort(u.begin(),u.end());
    sort(v.begin(),v.end());

    for (int i=0;i<u.size();i++) {
        int target = -u[i];

        int left = -1;
        int right = -1;

        int low = 0;
        int high = v.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if (v[mid] >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        left = low;

        low = 0;
        high = v.size();
        while(low < high) {
            int mid = (low + high) / 2;
            if (v[mid] <= target) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        right = high;

        if (right - left) {
            ans += right - left;
        }
    }

    cout << ans << endl;
    return 0;
}
