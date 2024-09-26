#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
int ans = 2000000001;
pair<int,int> solution;
int arr[100000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);

    int left = 0;
    int right = N-1;
    int sum;
    while(left < right) {
        sum = arr[left] + arr[right];
        if (ans > abs(sum)) {
            ans = abs(sum);
            solution.first = arr[left];
            solution.second = arr[right];
        }
        if (sum == 0) break;
        else if (sum > 0) right--;
        else if (sum < 0) left++;
    }

    cout << solution.first << ' ' << solution.second << '\n';
    return 0;
}
