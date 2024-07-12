#include <iostream>
#include <map>
using namespace std;
int N,M;
int ans=0;
map<string, int> m;
int main() {
    // ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
    
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        char tempstr[25];
        cin >> tempstr;
        m[tempstr] = 1;
    }
    for (int i=0;i<M;i++) {
        char tempstr[25];
        cin >> tempstr;
        if (m[tempstr] == 1) {
            m[tempstr] = 2;
            ans++;
        }

    }

    cout << ans << endl;
    for (auto iter : m) {
        if (iter.second == 2) {
            cout << iter.first << endl;
        }
    }

    
    return 0;
}
