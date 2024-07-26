#include <iostream>
#include <algorithm>
using namespace std;
int N;
int maxnum=0;
int arr[10];

int sumarr(int a) {
    return abs(arr[a] - arr[a+1]);
}

int main() {
    cin >> N;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }

    sort(arr,arr+N);

    do { 
        int temp = 0;
        for (int i=0;i<N-1;i++) {
            temp += sumarr(i);
        }
        if (maxnum < temp) {
            maxnum = temp;
        }
    } while(next_permutation(arr,arr+N));

    cout << maxnum;
    
    return 0;
}
