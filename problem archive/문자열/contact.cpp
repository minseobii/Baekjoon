#include <iostream>
#include <regex>
using namespace std;
int N;

bool matching(string s) {
    regex e("\\b(100+1+ | 01+)\\b");
    return regex_match(s,e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--) {
        string s;
        cin >> s;
        if (matching(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
