#include <iostream>
#include <queue>
using namespace std;
int N;
int visit[15];
int ans;

bool check(int x) {
    int q = visit[x];
    for (int i=0;i<x;i++) {
        if (visit[i] == q || (visit[i] + i == q+x) ||(visit[i]-i == q-x)) {
            return false;
        }
    }
    return true;
}

void Queen(int x) {
    if (x == N) {
        ans++;
        return;
    }
    else {
        for (int i=0;i<N;i++) {
            visit[x] = i;
            if (check(x)) {
                Queen(x+1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    Queen(0);
    
    cout << ans << endl;
    return 0;
}
