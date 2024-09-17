#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[15][8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num = 1;
    int count = 0;
    for (int i=0;i<8;i++) {
        for (int j=0;j<15;j++) {
            arr[j][i] = num;
            count++;

            if (count == 6) {
                num++;
                count = 0;
            }
        }
    }

    for (int i=0;i<15;i++) {
        for (int j=0;j<8;j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    } 

    return 0;
}
