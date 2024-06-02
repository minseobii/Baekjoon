#include <iostream>
using namespace std;

int N;
char arr[26][26];

int ans=0;
int ans_arr[1000];

int search(int i, int j) {
    if (arr[i][j] == '1') {
            ans_arr[ans]++;
            arr[i][j] = 0;
            if (i+1 < N) {
                search(i+1,j);
            }
            if (j+1 < N) {
                search(i,j+1);
            }
            if (i > 0) {
                search(i-1,j);
            }
            if (j > 0) {
                search(i,j-1);
            }
            return 1;
    }
    return 0;
}

int main() {
    cin >> N;

    for (int i=0;i<N;i++) { //input
       for (int j=0;j<N;j++) {
        char house;
        cin >> house;
        arr[i][j] = house;
       }
    } 

    for (int i=0;i<N;i++) { //search
       for (int j=0;j<N;j++) {
        if (arr[i][j] == '1') {
            if (search(i,j)) {
                ans++;
            }
        }
       }
    } 

    int min = ans_arr[0];

    for (int i=0;i<ans-1;i++) { //sort
        int min = i;
        for (int j=i+1;j<ans;j++) {
            if (ans_arr[i] >= ans_arr[j]) {
                int temp = ans_arr[i];
                ans_arr[i] = ans_arr[j];
                ans_arr[j] = temp;
            }
        }
    } 

    cout << ans << endl;

    for (int i=0;i<ans;i++) {
        cout << ans_arr[i] << endl;
    }    
    return 0;
}
