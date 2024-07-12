#include <iostream>
#include <vector>
using namespace std;
int N;

vector<int> v[100];
int visit[100] = {0,};

void dfs(int k) {
    for (int i=0;i<v[k].size();i++) {
        if (visit[v[k][i]] == 0) {
            visit[v[k][i]] = 1;
            dfs(v[k][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                v[i].push_back(j);
            }
        }
    }

    for (int i=0;i<N;i++) {
        dfs(i);
        for (int j=0;j<N;j++) {
            cout << visit[j] << ' ';
            visit[j] = 0;
        }
        cout << endl;
    }



    return 0;
}
