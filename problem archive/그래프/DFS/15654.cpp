#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[10] = {0,};
int ansarr[10] = {0,};
int visit[10] = {0,};

void DFS(int a) {
    if (a == M) {
        for (int i=0;i<M;i++) {
            cout << ansarr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else {
        for (int i=0;i<N;i++) {
            if (!visit[i]) {
                visit[i] = 1;
                ansarr[a] = arr[i];
                DFS(a+1);
                visit[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    DFS(0);
    return 0;
}
