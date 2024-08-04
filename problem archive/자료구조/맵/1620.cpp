#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N,M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    map<string, int> m1;
    map<int, string> m2;
    for (int i=1;i<N+1;i++) {
        string str;
        cin >> str;
        m1[str] = i;
        m2[i] = str;
    }

    for (int k=0;k<M;k++) {
        string str;
        cin >> str;
        if (atoi(str.c_str()) == 0) { //string
            cout << m1[str] << '\n';
        }
        else {  //int
            cout << m2[atoi(str.c_str())] << '\n';
        }
    }
    return 0;
}
