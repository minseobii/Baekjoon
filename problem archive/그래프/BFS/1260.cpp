#include <iostream>
using namespace std;
int N,M,V;

int arr[1001][1001];

int visited_dfs[1001];
int visited_bfs[1001];

int queue[1001]; 

int DFS(int a) {
    visited_dfs[a] = 1;
    cout << a << ' ';
    for (int i=1;i<=N;i++) {
        if (arr[a][i] && !visited_dfs[i]) {
            DFS(i);
        }
    }
    return 0;
}

int BFS(int start, int end) {
    int end_new = end;
    for (int i=start;i<end;i++) {
        int q = queue[i];
        for (int j=1;j<=N;j++) {
            if (arr[q][j] && !visited_bfs[j]) {
                visited_bfs[j] = 1;
                cout << j << ' ';
                queue[end_new++] = j;
            }
        }
    }
    if (end < end_new) BFS(end, end_new);
    return 0;
}

int main() {
    cin >> N >> M >> V;

    for (int i=0; i<M; i++) { //간선 생성
        int a,b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    DFS(V);
    
    cout << endl << V << ' ';
    visited_bfs[V] = 1;
    queue[0] = V;
    BFS(0,1);

    return 0;
}
