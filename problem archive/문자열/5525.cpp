#include <iostream>
#include <cstring>
using namespace std;
int N, M;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    char arr[M];
    int subarr[M] = {0,};
    char substr[5] = "IOI";

    for (int i=0;i<M;i++) {
        cin >> arr[i];
    }

    for (int i=0;i<M-2;i++) {
        if (strncmp(substr, arr+i, 3) == 0) {
            if (i-2 >= 0) {
                subarr[i] = subarr[i-2] + 1;
            }
            else {
                subarr[i] = 1;
            }
        }
        if (subarr[i] >= N) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
