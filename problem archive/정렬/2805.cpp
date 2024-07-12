#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int ans=0;

bool compare(int i,int j) {
    return j < i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    int arr[N+1] = {0,};

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N,compare);

    ans = arr[0];
    int tree=0;
    int idx=0;

    while(M > tree) {
        int diff = arr[idx] - arr[idx+1];

        if (diff == 0) {
            idx++;
            continue;
        }

        for (int i=0;i<diff;i++) {
            tree += idx+1;
            ans--;
            if (M <= tree) {
                break;
            }
        }
        idx++;
    }

    cout << ans << endl;
    return 0;
}
