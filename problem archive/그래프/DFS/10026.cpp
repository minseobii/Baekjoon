#include <iostream>

using namespace std;

int N;

char arr_in[101][101];
char arr[101][101];

int ans;
int ans_blind;

int search(int i, int j, char k) {
    if (arr[i][j]) {
        if (arr[i][j]==k) {
            //cout << arr[i][j];
            arr[i][j] = 0;
            if (i+1<N) {
                search(i+1,j,k);
            }
            if (j+1<N) {
                search(i,j+1,k);
            }
            if (i > 0) {
                search(i-1,j,k);
            }
            if (j > 0) {
                search(i,j-1,k);
            }
            
            return 1;
        }
    }
    return 0;
}

int main()
{   
    cin >> N;
    for (int i=0;i<N;i++) {
       for (int j=0;j<N;j++) {
        char color;
        cin >> color;
        arr[i][j] = color;
        arr_in[i][j] = color;
       }
    } 

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
        if (arr[i][j]) {
            if (search(i,j,arr[i][j])) {
                ans++;
            }
        }
        }
    }   

    for (int i=0;i<N;i++) {
       for (int j=0;j<N;j++) {
        arr[i][j] = arr_in[i][j];
        if (arr[i][j] == 'G') {
            arr[i][j] = 'R';
        }
       }
    } 

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
        if (arr[i][j]) {
            if (search(i,j,arr[i][j])) {
                ans_blind++;
            }
        }
        }
    }  

    cout << ans << ' ' << ans_blind;
}
