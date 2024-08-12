#include <iostream>
#define INF 2000000001
using namespace std;
int N;
int arr[100000];
int Minnum = INF;
int ans[2];

int cal(int a, int b) {
    return abs(a+b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N-1;

    while (left < right) {
        int tempnum = cal(arr[left],arr[right]);
        if (Minnum > tempnum) {
            Minnum = tempnum;
            ans[0] = arr[left];
            ans[1] = arr[right];
        }

        if (left + 1 == right) {
            break;
        }
        else {
            int l = cal(arr[left+1], arr[right]);
            int r = cal(arr[right-1], arr[left]);

            if (l < r) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
