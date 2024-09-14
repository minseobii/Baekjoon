#include <iostream>
#include <algorithm>
using namespace std;
int N,M,cost;

int ans[50];

int initial[10];
pair<int,int> arr[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i].first;
        arr[i].second = i;

        initial[i] = arr[i].first;
    }
    cin >> M;

    
    sort(arr,arr+N);

    int idx = 0;
    while(cost < M) {
        int num = 0;
        if (arr[num].first + cost <= M) {
            if (arr[num].second == 0 && idx == 0) {
                if (arr[num+1].first + cost <= M && N > 1) num++;
                else {
                    cout << 0;
                    return 0;
                }
            }

            ans[idx++] = arr[num].second;
            cost += arr[num].first;
        } 
        else break;
    } 

    for (int i=0;i<idx;i++) {
        for (int j=N-1;j>=0;j--) {
            if (cost + initial[j] - initial[ans[i]] <= M) {
                cost += (initial[j] - initial[ans[i]]);
                ans[i] = j;
                break;
            }
        }
    }

    for (int i=0;i<idx;i++) {
        cout << ans[i];
    }
    return 0;
}
