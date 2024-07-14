#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--) {
        string p;
        int n;
        int error_num = 0;
        char temp;
        vector<int> v;

        cin >> p >> n;
        cin >> temp;
        for (int i=0;i<n;i++) {
            int temp_int;
            cin >> temp_int;
            cin >> temp;
            v.push_back(temp_int);
        }
        if (v.empty()) {
            cin >> temp;
        }

        bool revers = false;
        int left = 0;
        int right = n;

        for (int i=0;i<p.size();i++) {
            if (p[i] == 'R') {
                //reverse(v.begin(), v.end());
                revers = !revers;
            }
            else {
                if (v.empty()) {
                    error_num = 1;
                    break;
                } 
                else {
                    //v.erase(v.begin());
                    if (revers) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
            if (right < left) {
                error_num = 1;
                break;
            }
        } 

        if (error_num == 1) {
            cout << "error" << '\n';
        }
        else {
            if (revers) {
                cout << '[';
                for (int i=right-1;i>=left;i--) {
                    cout << v[i];
                    if (i != left) {
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
            else {
                cout << '[';
                for (int i=left;i<right;i++) {
                    cout << v[i];
                    if (i != right-1) {
                        cout << ',';
                    }
                }
                cout << ']' << '\n';
            }
        }
    }
    return 0;
}
