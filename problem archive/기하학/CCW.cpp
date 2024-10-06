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
int arr[3][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=0;i<3;i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    int x1 = arr[1][0] - arr[0][0];
    int x2 = arr[2][0] - arr[1][0];
    int y1 = arr[1][1] - arr[0][1];
    int y2 = arr[2][1] - arr[1][1];
    int v = (x1*y2) - (x2*y1);

    if (v > 0) cout << 1 << '\n';
    else if (v < 0) cout << -1 << '\n';
    else cout << 0 << '\n';

    return 0;
}
