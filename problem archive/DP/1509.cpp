#include <iostream>
#include <vector>
#define INF 3000
using namespace std;
int N,ans;
string s;

vector<int> v[2500];
bool Pal[2500][2500];
int DP[2501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    N = s.size();

    for (int j=0;j<N;j++) {
        DP[j+1] = INF;
        for (int i=0;i<N;i++) {
            if (j == 0) {
                Pal[i][i] = true;
                v[i].push_back(i);
                continue;
            }

            else if (j == 1) {
                if (s[i] == s[i+1]) {
                    Pal[i][i+1] = true;
                    v[i+1].push_back(i);
                }
                continue;
            }

            if (i+j < N && s[i] == s[i+j] && Pal[i+1][i+j-1]) {
                Pal[i][i+j] = true;
                v[i+j].push_back(i);
            }
        }
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<v[i].size();j++) {
            int x = v[i][j];

            DP[i+1] = min(DP[i+1],DP[x]+1);
        }
    }
    
    cout << DP[N] << endl;
    return 0;
}
