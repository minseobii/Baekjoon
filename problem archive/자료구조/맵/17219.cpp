#include <iostream>
#include <map>
using namespace std;
int N,M;
map<string, string> m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=0;i<N;i++) {
        string site, pw;
        cin >> site >> pw;
        m[site] = pw;
    }
    for (int i=0;i<M;i++) {
        string question;
        cin >>question;
        cout << m[question] << '\n';
    }
    return 0;
}
