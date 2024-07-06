#include <iostream>
#include <map>
using namespace std;
int x;
int main() {
    cin >> x;
    while(!cin.eof()) {
        map<int, char> m;
        int n;
        int ans=0;
        int l=0;
        bool find = false;
        x = x*10000000;
        cin >> n;
        for (int i=0;i<n;i++) {
            int temp;
            cin >> temp;
            m[temp] = 'O';
        }
        
        for (auto iter : m) {
          cout << iter.first << ' ' << iter.second << endl;
            if (x - iter.first < 10000001) {
              if (m[x-iter.first] == 'O') {
                  find = true;
                  l = min(iter.first, x-iter.first);
                  ans = max(ans,abs(x-2*iter.first));
              }
              else {
                m.erase(x - iter.first);
              }
            }
        }
        
        if (find == true) {
            cout << "yes " << l << ' ' << x-l << endl;
        }
        else {
            cout << "danger" << endl;
        }
    }
    return 0;
}
