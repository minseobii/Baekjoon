#include <iostream>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N] = {0,};
    int num[N] = {0,};
    int ans=0;
    for (int i=0;i<N;i++) {
        int input;
        cin >> input;
        arr[i] = input;
    }
    for (int i=0;i<N;i++) {
        int temp=0;
        for (int j=0;j<i;j++) {
            if (arr[j] < arr[i]) {
                temp = max(temp, num[j]);
            }
        }
        num[i] = temp+1;
    }
    for (int i=0;i<N;i++) {
        ans = max(ans, num[i]);
    }
    cout << ans << endl;
    return 0;
}
