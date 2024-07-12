#include <iostream>
#include <algorithm>
using namespace std;
int x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (cin >> x) {
        x *= 10000000;
        int n;
        cin >> n;

        int l1=0;
        int l2=0;
        int arr[n];

        for (int i=0;i<n;i++) {
            cin >> arr[i];
        }
        sort(arr,arr+n);

        int left = 0;
        int right = n-1;
        while(left < right) {
            int sumlenght = arr[left] + arr[right];
            if (sumlenght == x) {
                l1 = arr[left];
                l2 = arr[right];
                break;
            }
            else if (sumlenght < x) {
                left++;
            }
            else {
                right--;
            }
        }

        if (l1) {
            cout << "yes " << l1 << ' ' << l2 << endl;
        }
        else {
            cout << "danger" << endl;
        }
    }
    return 0;
}
