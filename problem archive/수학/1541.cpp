#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
int ans=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len=0;
    char x;
    char arr[51];

    while(cin >> x) {
        arr[len++] = x;
    }

    int num=0;
    int ans=0;
    int minus=0;
    for (int i=0;i<len;i++) {
        if (isdigit(arr[i])) {
            num = (10 * num) + arr[i] - '0';
        }
        else {
            if (minus) {
                ans -= num;
            }
            else {
                ans += num;
            }

            if (arr[i] == '-') {
                minus = 1;
            }
            num = 0;
        }
    }
    if (minus) {
         ans -= num;
    }
    else {
        ans += num;
    }

    cout << ans << endl;

    return 0;
}
