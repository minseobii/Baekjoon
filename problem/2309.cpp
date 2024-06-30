#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int subarr[9] = {0,0,1,1,1,1,1,1,1}; 
int main() {
    for (int i=0;i<9;i++) {
        cin >> arr[i];
    }
    
    do { 
        int temparr[7] = {0,};
        int idx=0;
        int sum=0;
        for(int i=0;i<9;i++) {
            if (subarr[i] == 1) {
                sum += arr[i];
                temparr[idx++] = arr[i];
            }
        }
        if (sum == 100) {
            sort(temparr,temparr+7);
            for (int i=0;i<7;i++) {
                cout << temparr[i] << endl;
            }
            break;
        }

    } while(next_permutation(subarr,subarr+9));
    
    return 0;
}
