#include <iostream>
#include <cmath>
using namespace std;
int N, K;
int subarr[11];
bool arr[4000][10000];

int sqrt2(int a) {
    int b=0;
    while(a) {
        b++;
        a /= 2;
    }
    return b-1;
}

void star(int i, int j, int k) {
    if (k == 1) {
        for (int a=0;a<5;a++) {
            arr[i][j+a] = true;
        }
        for (int a=1;a<5;a+=2) {
            arr[i-1][j+a] = true;
        }
        arr[i-2][j+2] = true;
    }
    else {
        star(i,j,k/2);
        if (k == 2) {
            star(i-3,j+3,1);
        }
        else {
            star(i-((k/2)*3),j+(subarr[sqrt2(k/4)]+1),k/2);
        }
        star(i,j+(subarr[sqrt2(k/2)]+1),k/2);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    K = N / 3;
    for (int i=0;i<11;i++) {
        if (i==0) {
            subarr[i] = 5;
        }
        else {
            subarr[i] = subarr[i-1] * 2 + 1;
        }
    }
    
    star(N,1,K);

    for (int i=1;i<=N;i++) {
        for (int j=1;j<=subarr[sqrt2(K)];j++) {
            if (arr[i][j]) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
    return 0;
}
