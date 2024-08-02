#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> Party[50];
int PartyIdx[50];
int visit[51];
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    queue<int> q;

    int Temp;
    cin >> Temp;
    while (Temp--) {
        int person;
        cin >> person;
        q.push(person);
        visit[person] = 1; 
    }

    for (int i=0;i<M;i++) {
        int num;
        cin >> num;
        PartyIdx[i] = num;

        while(num--) {
            int person;
            cin >> person;
            Party[i].push_back(person);
        }
    }

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for (int i=0;i<M;i++) {
            int find = 0;
            if (PartyIdx[i] == 0) {
                continue;
            }
            for (int j=0;j<Party[i].size();j++) {
                if (Party[i][j] == a) {
                    find = 1;
                }
            }
            if (find) {
                PartyIdx[i] = 0;
                for (int j=0;j<Party[i].size();j++) {
                    if (Party[i][j] != a) {
                        if (visit[Party[i][j]] == 0) {
                            q.push(Party[i][j]);
                            visit[Party[i][j]] = 1;
                        }
                    }
                }
            }
        }
    }

    for (int i=0;i<M;i++) {
        if (PartyIdx[i]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
