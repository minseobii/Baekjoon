#include <iostream>
#include <queue>
using namespace std;
int N;
long long ans;
priority_queue<int> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        long long k;
        cin >> k;
        pq.push(-k);
    }

    while(!pq.empty()) {
        int a = -pq.top();
        pq.pop();

        if(pq.empty()) {
            break;
        }

        int b = -pq.top();
        pq.pop();

        pq.push(-(a+b));
        ans += a+b;
    }
    cout << ans << endl;
    return 0;
}
