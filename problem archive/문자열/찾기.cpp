#include <iostream>
#include <string>
#include <vector>
using namespace std;
string T,P;
int F[1000001];
int Tn,Pn,ans;
vector<int> v;

void getfail() {
    if (Pn == 1) return;

    int i=1;
    int j=0;
    while(i < Pn) {
        if (P[i] == P[j]) {
            F[i] = j+1;
            i++;
            j++;
        }
        else if (j > 0) j = F[j-1];
        else {
            F[j] = 0;
            i++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    getline(cin,T,'\n');
    getline(cin,P);
    Tn = T.length();
    Pn = P.length();

    getfail();

    int i = 0;
    int j = 0;
    while(i < Tn) {
        if (T[i] == P[j]) {
            if (j == Pn-1) {
                ans++;
                v.push_back(i - j + 1);

                j = F[j];
                i++;
                continue;
            }
            i++;
            j++;
        }
        else if (j > 0) j = F[j-1];
        else i++;
    }

    cout << ans << '\n';
    for (int i=0;i<v.size();i++) {
        cout << v[i] << ' ';
    }
    return 0;
}
