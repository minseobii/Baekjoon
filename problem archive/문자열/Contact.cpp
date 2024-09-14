#include <iostream>
using namespace std;
int T,l;

string s;

bool ispattern(int idx) {
    while(idx < l) {
        if (s[idx] == '0') {
            if (idx+1 < l) {
                if (s[idx+1] == '0') return false;
                else idx += 2;
            } 
            else return false;
        }
        else {
            idx++;
            if (idx < l) {
                if (s[idx] == '1') return false;
                else {
                    idx++;
                    if (idx < l && s[idx] == '0') {
                        while(idx < l && s[idx] == '0') idx++;
                        if (idx < l && s[idx] == '1') {
                            idx++;
                            while(idx < l && s[idx] == '1') {
                                if (ispattern(idx)) return true;
                                else {
                                    idx++;
                                }
                            }
                        }
                        else return false;
                    }
                    else return false;
                }
            }   
            else return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> s;
        l = s.length();
        if (ispattern(0) == false) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}
