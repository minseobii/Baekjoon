#include <iostream>
#include <vector>
using namespace std;
int N,ans;
bool notprime[4000001];
vector<int> prime;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    if (N == 1) {
        cout << 0 <<'\n';
        return 0;
    }

    for (int i=2;i*i<=N;i++) {
        if (notprime[i]) {
            continue;
        }
        for (int j=i*i;j<=N;j+=i) {
            notprime[j] = true;
        }
    }

    for (int i=2;i<=N;i++) {
        if (!notprime[i]) prime.push_back(i);
    }

    int left = 0;
    int right = 0;
    int sum = 0;
    int n = prime.size();
    while (left <= right && right <= n) {
        if (sum == N) {
            sum += prime[right++];
            ans++;
        }
        else if (sum < N) {
            sum += prime[right++];
        }
        else if (sum > N) {
            sum -= prime[left++];
        }
    }

    cout << ans << endl;
    return 0;
}
