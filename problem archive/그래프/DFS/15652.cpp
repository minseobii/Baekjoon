#include <iostream>
using namespace std;
int N,M;
int arr[10] = {0,};

void DFS(int a, int b) {
    if (b == M) {
        for (int i=0;i<M;i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    else {
        for (int i=a;i<=N;i++) {  
            arr[b] = i;  
            DFS(i,b+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    DFS(1,0);
    return 0;
}
