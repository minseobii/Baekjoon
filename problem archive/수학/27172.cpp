#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;
bool input[1000001];
int ans[1000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a;
        cin >> a;
        input[a] = true;
        v.push_back(a);
    }

    for (int i=0;i<N;i++) {
        int x = v[i];
        for (int j=1;j*j<=x;j++) {
            if (x%j == 0) {
                if (input[j]) {
                    ans[j]++;
                    ans[x]--;
                }
                int div = x/j;
                if (div != j && input[div]) {
                    ans[div]++;
                    ans[x]--;
                }
            }
        }
    }

    for (int i=0;i<N;i++) {
        cout << ans[v[i]] << ' ';
    }
    cout << '\n';
    return 0;
}