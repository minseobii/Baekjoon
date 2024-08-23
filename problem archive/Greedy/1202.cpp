#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,K;
long long ans;
pair<int,int> Jewel[300000];
int Bag[300000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    priority_queue<pair<int,int>> pq;

    for (int i=0;i<N;i++) {
        cin >> Jewel[i].first >> Jewel[i].second;
    }
    for (int i=0;i<K;i++) {
        cin >> Bag[i];
    }

    sort(Jewel,Jewel+N);
    sort(Bag,Bag+K);

    int j = 0;
    for (int i=0;i<K;i++) {
        while(Jewel[j].first <= Bag[i] && j < N) {
            pq.push({Jewel[j].second, Jewel[j].first});
            j++;
        }
        
        if (!pq.empty()) {
            ans += pq.top().first;
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}
