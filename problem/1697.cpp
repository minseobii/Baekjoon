#include <iostream>
#include <queue>
using namespace std;

int N,K;
queue<int> q;

int append_q(int ans) {
    int find=0;

    if (ans == 0) {
        q.push(N);
        if (N == K) {
          find = 1;
        }
    }

    else {
        int arr[2] = {1,-1};
        int n = q.front();
        int new_n;
        q.pop();
        for (int i=0;i<3;i++) {
            if (i == 2) {
                new_n = n * 2;
            }
            else {
                new_n = n + arr[i];
            }

            if (new_n == K) {
                find = 1;
                break;
            }
            else {
                q.push(new_n);
            }
        }

    }


    if (find) {
        cout << ans;
        return 0;
    }
    else {
        append_q(ans+1);
    }
    return 0;
}

int main() {
    cin >> N >> K;
    append_q(0);
    return 0;
}
