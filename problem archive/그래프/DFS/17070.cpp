#include <iostream>
using namespace std;
int N;
int ans;
int arr[20][20];

void DFS(int i, int j, char type) {
    if (i == N && j == N) {
        ans++;
        return;
    }

    if (type == 'a') {
        if (j < N && arr[i][j+1] == 0) {
            DFS(i,j+1,'a');
        }
        if (j < N && i < N && arr[i][j+1] == 0 && arr[i+1][j] == 0 && arr[i+1][j+1] == 0) {
            DFS(i+1,j+1,'c');
        }
    }
    else if (type == 'b') {
        if (i < N && arr[i+1][j] == 0) {
            DFS(i+1,j,'b');
        }
        if (j < N && i < N && arr[i][j+1] == 0 && arr[i+1][j] == 0 && arr[i+1][j+1] == 0) {
            DFS(i+1,j+1,'c');
        }
    }
    else if (type == 'c') {
        if (j < N && arr[i][j+1] == 0) {
            DFS(i,j+1,'a');
        }
        if (i < N && arr[i+1][j] == 0) {
            DFS(i+1,j,'b');
        }
        if (j < N && i < N && arr[i][j+1] == 0 && arr[i+1][j] == 0 && arr[i+1][j+1] == 0) {
            DFS(i+1,j+1,'c');
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    DFS(1,2,'a');
    cout << ans << endl;
    return 0;
}
