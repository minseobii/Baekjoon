#include <iostream>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int arr[N+1];
    int square = 0;
    for (int i=1;i<N+1;i++) {
        if (i == ((square+1) * (square+1))) {
            arr[i] = 1;
            square++;
        }
        else {
            int temp = square;
            int num = 4;
            while(temp > 0) {
                num = min(arr[i - temp*temp]+1, num);
                temp--;
            }
            arr[i] = num;
        } 
    }
    cout << arr[N] << '\n';
    return 0;
}
