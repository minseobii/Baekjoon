#include <iostream>
using namespace std;
string s;
int l;

void init() {
    int idx = 0;
    while(s[idx] == '9'){
        s[idx] = '0';
        idx++;
    }
    if (idx == l) l++;
    s[idx] = (s[idx]-'0'+1)+'0';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    l = s.length();

    init();
    
    while()

    cout << s << endl;
    return 0;
}
