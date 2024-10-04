#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
#define INF 1000000001
using namespace std;
int N,ans;
double d = 1;
int arr[50];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<N;i++) {
        int count = 0;
        int left = i-1;
        int right = i+1;

        double tanl = -INF;
        while(left >= 0) {
            double temp = (-d) * (arr[i] - arr[left]) / (i - left);
            if (temp > tanl) {
                tanl = temp;
                count++;
            }
            left--;
        }

        double tanr = -INF;
        while(right < N) {
            double temp = (d) * (arr[i] - arr[right]) / (i - right);
            if (temp > tanr) {
                tanr = temp;
                count++;
            }
            right++;
        }

        ans = max(ans, count);
    }

    cout << ans << '\n';
    return 0;
}
