#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N,ans;
int arr[2000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);

    for (int k=0;k<N;k++) {
        int left = 0;
        int right = N-1;
        int sum;

        while(left < right) {
            sum = arr[left] + arr[right];
            if (left == k) {
                left++;
                continue;
            }
            if (right == k) {
                right--;
                continue;
            }

            if (sum == arr[k]) {
                ans++;
                break;
            }
            else if (sum > arr[k]) {
                right--;
            }
            else if (sum < arr[k]) {
                left++;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
