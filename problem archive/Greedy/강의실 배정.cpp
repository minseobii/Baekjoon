#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,T,ans;

pair<int,int> arr[200000];
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        arr[i] = {a,b};
    }
    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        if (pq.empty()) {
            pq.push(-arr[i].second);
            ans++;
            continue;
        }

        int t = -pq.top();

        if (t <= arr[i].first) {
            pq.pop();
            pq.push(-arr[i].second);
        }
        else {
            pq.push(-arr[i].second);
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
