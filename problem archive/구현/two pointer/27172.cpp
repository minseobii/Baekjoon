#include <iostream>
using namespace std;
int N,S;
int idx = -1;
int arr[100000];    
int s[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
        s[i] = s[i-1] + arr[i];
        if (idx == -1 && s[i] >= S) {
            idx = i;
        }
    }
    if (idx == -1) {
        cout << 0 << '\n';
    }
    else {
        int left = 0;
        int right = 1;
        int sum = arr[1];
        int len = 100001;

        while(right <= N && left < right) {
            if (sum >= S) {
                len = min(len, right-left);
                sum -= arr[++left];
            }
            else {
                sum += arr[++right];
            }
        }

        cout << len << endl;
    }
    return 0;
}
