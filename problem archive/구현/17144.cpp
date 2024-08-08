#include <iostream>
using namespace std;
int R,C,T;
int arr[50][50];
int ans;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};

struct PAIR {
    int r,c;
};

PAIR air1;
PAIR air2;

void Deffusion() {
    int temp[50][50] = {0,};
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (arr[i][j] > 0) {
                int sum=0;
                for (int k=0;k<4;k++) {
                    int ni = i + di[k];
                    int nj = j + dj[k];

                    if (ni < 0 || nj < 0 || ni >= R || nj >= C ||
                        (ni == air1.r && nj == air1.c) || (ni == air2.r && nj == air2.c)) {
                            continue;
                    }
                    
                    temp[ni][nj] += arr[i][j] / 5;
                    sum += arr[i][j] / 5;
                }
                temp[i][j] -= sum;
            }
        }
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            arr[i][j] += temp[i][j];
        }
    }
}

void Clear() {
    for (int i = air1.r-2;i>=0;i--) {
        arr[i+1][0] = arr[i][0];
    }

    for (int i=1;i<C;i++) {
        arr[0][i-1] = arr[0][i];
    }

    for (int i=1;i<=air1.r;i++) {
        arr[i-1][C-1] = arr[i][C-1];
    }

    for (int i=C-2;i>=1;i--) {
        if (i == 1) {
            arr[air1.r][i+1] = arr[air1.r][i];
            arr[air1.r][i] = 0;
        }
        else {
            arr[air1.r][i+1] = arr[air1.r][i];
        } 
    }


    for (int i=air2.r+2;i<R;i++) {
        arr[i-1][0] = arr[i][0];
    }

    for (int i=1;i<C;i++) {
        arr[R-1][i-1] = arr[R-1][i];
    }

    for (int i = R-2;i>=air2.r;i--) {
        arr[i+1][C-1] = arr[i][C-1];
    }

    for (int i=C-2;i>=1;i--) {
        if (i == 1) {
            arr[air2.r][i+1] = arr[air2.r][i];
            arr[air2.r][i] = 0;
        }
        else {
            arr[air2.r][i+1] = arr[air2.r][i];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> T;
    
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1 && air1.r == air2.r) {
                air1 = {i,j};
                air2 = {i+1,j};
            }
        }
    }

    while(T--) {
        Deffusion();
        Clear();
    }

    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (arr[i][j] > 0) {
                ans += arr[i][j];
            }
        }
    }
    cout << ans << endl;
    return 0;
}
