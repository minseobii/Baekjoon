#include <iostream>
using namespace std;
int arr[9][9];
int ans[9][9];
bool row[9][10];
bool col[9][10];
bool square[9][10];

bool check(int a, int b, int c, int i) {
    if (row[a][i] == false && col[b][i] == false && square[c][i] == false) {
        return true;
    }
    return false;
}

void init(int a, int b, int c, int i) {
    row[a][i] = true;
    col[b][i] = true;
    square[c][i] = true;
    arr[a][b] = i;
}

void delnum(int a, int b, int c, int i) {
    row[a][i] = false;
    col[b][i] = false;
    square[c][i] = false;
    ans[a][b] = 0;
}

void putnum(int a, int b, int c, int i) {
    row[a][i] = true;
    col[b][i] = true;
    square[c][i] = true;
    ans[a][b] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            char a;
            cin >> a;
            int s = (j/3) + ((i/3)*3);
            init(i,j,s,a-'0');
        }
    }

    int x = 0;
    bool backtracking = false;
    while(x <= 80) {
        int r = x/9;
        int c = x%9;
        int s = (c/3) + ((r/3)*3);

        int temp = -1;

        if (arr[r][c]) {
            if (backtracking) x--;
            else x++;
            continue;
        }

        else {
            if (backtracking) {
                for (int i=ans[r][c]+1;i<=9;i++) {
                    if (check(r,c,s,i)) {
                        temp = i;
                        break;
                    }
                }

                if (temp == -1) {
                    delnum(r,c,s,ans[r][c]);
                    x--;
                    continue;
                }
                else {
                    delnum(r,c,s,ans[r][c]);
                    putnum(r,c,s,temp);
                    x++;
                    backtracking = false;
                    continue;
                }
            }
            else {
                for (int i=1;i<=9;i++) {
                    if (check(r,c,s,i)) {
                        temp = i;
                        break;
                    }
                }

                if (temp == -1) {
                    backtracking = true;
                    x--;
                }
                else {
                    putnum(r,c,s,temp);
                    x++;
                }
            }
        }
    }
    
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (arr[i][j]) cout << arr[i][j];
            else cout << ans[i][j]; 
        }
        cout << '\n';
    }
    return 0;
}
