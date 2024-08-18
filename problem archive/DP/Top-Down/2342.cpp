#include <iostream>
#define INF 400001
using namespace std;
int ans;
int n = 1;
int arr[100000];
int subarr[5][5] = {{0,2,2,2,2}, {0,1,3,4,3}, {0,3,1,3,4}, {0,4,3,1,3}, {0,3,4,3,1}};
int DParr[100000][5][5];

int dp(int left, int right, int i) {
    if ((left != 0) && (right != 0) && (left == right)) return INF;
    if (i == n-1) return 0;
    if (DParr[i][left][right]) return DParr[i][left][right];

    DParr[i][left][right] = min(dp(arr[i+1],right,i+1)+subarr[left][arr[i+1]],dp(left,arr[i+1],i+1)+subarr[right][arr[i+1]]);
    return DParr[i][left][right];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a;
    cin >> a;
    while(a) {
        arr[n++] = a;
        cin >> a;
    }

    cout << dp(0,0,0) << endl;
    
    return 0;
}
