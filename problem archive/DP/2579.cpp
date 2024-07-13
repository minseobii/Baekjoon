#include <iostream>
using namespace std;
int N;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N+1];
    pair<int,int> maxarr[N+1];
    arr[0] = 0;
    maxarr[0] = {0,0};
    for (int i=1;i<N+1;i++) {
        cin >> arr[i];
    }
    for (int i=1;i<N+1;i++) {
        if (i==1) {
            maxarr[i] = {arr[i],arr[i]};
        }
        else if (i==2) {
            maxarr[i] = {arr[i],arr[i]+arr[i-1]};
        }
        else {
            int temp1 = max(maxarr[i-2].first, maxarr[i-2].second);
            int temp2 = maxarr[i-1].first;
            maxarr[i] = {temp1+arr[i], temp2+arr[i]};
        }
    }
    cout << max(maxarr[N].first,maxarr[N].second) << '\n';
    return 0;
}
