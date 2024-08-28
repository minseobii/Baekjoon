#include <iostream>
using namespace std;
int N,M;
int arr[10];
int visit[10];

void DFS(int a) {
    if (a == M) {
        for (int i=0;i<M;i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i=1;i<=N;i++) {
            if (visit[i] == 0) {
                arr[a] = i;
                visit[i] = 1;
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
    DFS(0);
    return 0;
}
