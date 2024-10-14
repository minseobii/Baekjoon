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

void spinpos(int k) {
    char temp = cube[k][0][1];
    cube[k][0][1] = cube[k][1][0];
    cube[k][1][0] = cube[k][2][1];
    cube[k][2][1] = cube[k][1][2];
    cube[k][1][2] = temp;

    temp = cube[k][0][2];
    cube[k][0][2] = cube[k][0][0];
    cube[k][0][0] = cube[k][2][0];
    cube[k][2][0] = cube[k][2][2];
    cube[k][2][2] = temp;
}

void spinneg(int k) {
    char temp = cube[k][0][1];
    cube[k][0][1] = cube[k][1][2];
    cube[k][1][2] = cube[k][2][1];
    cube[k][2][1] = cube[k][1][0];
    cube[k][1][0] = temp;

    temp = cube[k][0][2];
    cube[k][0][2] = cube[k][2][2];
    cube[k][2][2] = cube[k][2][0];
    cube[k][2][0] = cube[k][0][0];
    cube[k][0][0] = temp;
}

void spinU() {
    char a = cube[2][0][0];
    char b = cube[2][0][1];
    char c = cube[2][0][2];
    cube[2][0][0] = cube[5][0][0];
    cube[2][0][1] = cube[5][0][1];
    cube[2][0][2] = cube[5][0][2];
    cube[5][0][0] = cube[3][0][0];
    cube[5][0][1] = cube[3][0][1];
    cube[5][0][2] = cube[3][0][2];
    cube[3][0][0] = cube[4][0][0];
    cube[3][0][1] = cube[4][0][1];
    cube[3][0][2] = cube[4][0][2];
    cube[4][0][0] = a;
    cube[4][0][1] = b;
    cube[4][0][2] = c;
}

void spinD() {
    char a = cube[2][2][0];
    char b = cube[2][2][1];
    char c = cube[2][2][2];
    cube[2][2][0] = cube[4][2][0];
    cube[2][2][1] = cube[4][2][1];
    cube[2][2][2] = cube[4][2][2];
    cube[4][2][0] = cube[3][2][0];
    cube[4][2][1] = cube[3][2][1];
    cube[4][2][2] = cube[3][2][2];
    cube[3][2][0] = cube[5][2][0];
    cube[3][2][1] = cube[5][2][1];
    cube[3][2][2] = cube[5][2][2];
    cube[5][2][0] = a;
    cube[5][2][1] = b;
    cube[5][2][2] = c;
}

void spinF() {
    char a = cube[0][2][0];
    char b = cube[0][2][1];
    char c = cube[0][2][2];
    cube[0][2][0] = cube[4][2][2];
    cube[0][2][1] = cube[4][1][2];
    cube[0][2][2] = cube[4][0][2];
    cube[4][2][2] = cube[1][2][0];
    cube[4][1][2] = cube[1][2][1];
    cube[4][0][2] = cube[1][2][2];
    cube[1][2][0] = cube[5][0][0];
    cube[1][2][1] = cube[5][1][0];
    cube[1][2][2] = cube[5][2][0];
    cube[5][0][0] = a;
    cube[5][1][0] = b;
    cube[5][2][0] = c;
}

void spinB() {
    char a = cube[0][0][0];
    char b = cube[0][0][1];
    char c = cube[0][0][2];
    cube[0][0][0] = cube[5][0][2];
    cube[0][0][1] = cube[5][1][2];
    cube[0][0][2] = cube[5][2][2];
    cube[5][0][2] = cube[1][0][0];
    cube[5][1][2] = cube[1][0][1];
    cube[5][2][2] = cube[1][0][2];
    cube[1][0][0] = cube[4][2][0];
    cube[1][0][1] = cube[4][1][0];
    cube[1][0][2] = cube[4][0][0];
    cube[4][2][0] = a;
    cube[4][1][0] = b;
    cube[4][0][0] = c;
}

void spinL() {
    char a = cube[0][2][0];
    char b = cube[0][1][0];
    char c = cube[0][0][0];
    cube[0][2][0] = cube[3][0][2];
    cube[0][1][0] = cube[3][1][2];
    cube[0][0][0] = cube[3][2][2];
    cube[3][0][2] = cube[1][0][2];
    cube[3][1][2] = cube[1][1][2];
    cube[3][2][2] = cube[1][2][2];
    cube[1][0][2] = cube[2][2][0];
    cube[1][1][2] = cube[2][1][0];
    cube[1][2][2] = cube[2][0][0];
    cube[2][2][0] = a;
    cube[2][1][0] = b;
    cube[2][0][0] = c;
}

void spinR() {
    char a = cube[0][0][2];
    char b = cube[0][1][2];
    char c = cube[0][2][2];
    cube[0][0][2] = cube[2][0][2];
    cube[0][1][2] = cube[2][1][2];
    cube[0][2][2] = cube[2][2][2];
    cube[2][0][2] = cube[1][2][0];
    cube[2][1][2] = cube[1][1][0];
    cube[2][2][2] = cube[1][0][0];
    cube[1][2][0] = cube[3][2][0];
    cube[1][1][0] = cube[3][1][0];
    cube[1][0][0] = cube[3][0][0];
    cube[3][2][0] = a;
    cube[3][1][0] = b;
    cube[3][0][0] = c;
}

void cal(char plane, char dir) {
    if (plane == 'U') {
        if (dir == '+') {
            spinpos(0);
            spinU();
        }
        else {
            spinneg(0);
            for (int i=0;i<3;i++) {
                spinU();
            }
        }
    }
    else if (plane == 'D') {
        if (dir == '+') {
            spinpos(1);
            spinD();
        }
        else {
            spinneg(1);
            for (int i=0;i<3;i++) {
                spinD();
            }
        }
    }
    else if (plane == 'F') {
        if (dir == '+') {
            spinpos(2);
            spinF();
        }
        else {
            spinneg(2);
            for (int i=0;i<3;i++) {
                spinF();
            }
        }
    }
    else if (plane == 'B') {
        if (dir == '+') {
            spinpos(3);
            spinB();
        }
        else {
            spinneg(3);
            for (int i=0;i<3;i++) {
                spinB();
            }
        }
    }
    else if (plane == 'L') {
       if (dir == '+') {
            spinpos(4);
            spinL();
        }
        else {
            spinneg(4);
            for (int i=0;i<3;i++) {
                spinL();
            }
        }
    }
    else if (plane == 'R') {
        if (dir == '+') {
            spinpos(5);
            spinR();
        }
        else {
            spinneg(5);
            for (int i=0;i<3;i++) {
                spinR();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    map<int,char> m;
    m[0] = 'w';
    m[1] = 'y';
    m[2] = 'r';
    m[3] = 'o';
    m[4] = 'g';
    m[5] = 'b';
    while(T--) {
        cin >> N;
        for (int k=0;k<6;k++) {
            for (int i=0;i<3;i++) {
                for (int j=0;j<3;j++) {
                    cube[k][i][j] = m[k];
                }
            }
        }

        for (int i=0;i<N;i++) {
            char plane, dir;
            cin >> plane >> dir;
            cal(plane, dir);
        }
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                cout << cube[0][i][j];
            }
            cout <<'\n';
        }
    }
    return 0;
}
