#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1000000001
using namespace std;
int N;
long long ans;
int A[1000];
pair<int,int> arr[1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
        arr[i] = {A[i], i};
    }

    sort(arr,arr+N);

    for (int i=0;i<N;i++) {
        int idx = arr[i].second;

        int left = idx;
        int right = idx;
        int num = INF;
        while(left > 0 && A[idx] == A[left-1]) {
            left--;
        }
        if (left != 0) num = min(num, A[left-1]);
        while(right < N-1 && A[idx] == A[right+1]) {
            right++;
        }   
        if (right != N-1) num = min(num, A[right+1]);

        if (left == 0 && right == N-1) break;
        if (num < A[idx]) continue;

        int dif = num - A[idx];
        for (int i=left;i<=right;i++) {
            A[i] = num;
        }

        ans += dif;
    }

    cout << ans << '\n';
    return 0;
}
