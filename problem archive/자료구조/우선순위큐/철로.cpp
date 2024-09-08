#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,D,num,ans;
pair<int,int> arr[100001];
priority_queue<int> pq;

void insert(int a) {
    pq.push(a);
    num++;
}

void del(int s) {
    while(!pq.empty()) {
        if ((-pq.top()) < s) {
            pq.pop();
            num--;
        }
        else {
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        if (a < b) swap(a,b);

        arr[i] = {a,b};
    }
    cin >> D;
    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        int s = arr[i].first - D;

        insert(-arr[i].second);
        del(s);

        ans = max(ans, num);
    }

    cout << ans << endl;
    return 0;
}
