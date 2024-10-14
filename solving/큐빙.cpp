#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int T,N;
char cube[6][3][3];

void spin() {

}

void cal(char plane, char dir) {
    if (plane == 'U') {
        if (dir == '+') {
            spin(2,5,3,4,);
        }
        else {

        }
    }
    else if (plane == 'D') {
        if (dir == '+') {

        }
        else {
            
        }
    }
    else if (plane == 'F') {
        if (dir == '+') {

        }
        else {
            
        }
    }
    else if (plane == 'B') {
        if (dir == '+') {

        }
        else {
            
        }
    }
    else if (plane == 'L') {
        if (dir == '+') {

        }
        else {
            
        }
    }
    else if (plane == 'R') {
        if (dir == '+') {

        }
        else {
            
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        cin >> N;
        for (int i=0;i<N;i++) {
            char plane, dir;
            cin >> plane >> dir;
            cal(palne, dir);
        }
    }
    cout << ans << '\n';
    return 0;
}
