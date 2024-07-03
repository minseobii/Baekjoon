#include <iostream>
#include <algorithm>
using namespace std;
int inputarr[10];

long long int maxnum=0;
long long int minnum=0;
int maxzero = 0;
int minzero = 0;

int main() {
    int K;
    cin >> K;

    for (int i=0;i<K;i++) {
        char temp; 
        cin >> temp;
        if (temp == '>') {
            inputarr[i] = 1;
        }
        else {
            inputarr[i] = 0;
        }
    }

    int subarr[10];
    for (int i=0;i<10;i++) {
        if (i <= K) {
          subarr[i] = 1;
        }
        else {
          subarr[i] = 0;
        }
    }
    
    
    
    do { 
        int arr[K+1] = {0,};
        int idx = 0;      
        for(int i=0;i<10;i++) {
            if (subarr[i] == 1) {
                arr[idx++] = i;
            }
        }
         
        do {
            long long int temp = 0;
            int wrong = 0;
            for (int i=0;i<K;i++) {
                if (inputarr[i] == 1) {
                if (arr[i] > arr[i+1]) {
                    continue;
                }
                else {
                    wrong = 1;
                    break;
                }
                }
                else if (inputarr[i] == 0) {
                if (arr[i] < arr[i+1]) {
                    continue;
                }
                else {
                    wrong = 1;
                    break;
                }
                }
                
            }
            
            if (wrong) {
                continue;
            }
            else {
                for (int i=0;i<K+1;i++) {
                    temp = (temp * 10) + arr[i];
                }
                
                if (maxnum < temp) {
                    maxnum = temp;
                    if (arr[0] == 0) {
                        maxzero = 1;
                    }
                    else {
                        maxzero = 0;
                    }
                }

                if (minnum == 0) {
                    minnum = temp;
                    if (arr[0] == 0) {
                        minzero = 1;
                    }
                    else {
                        minzero = 0;
                    }
                }
                else if (minnum > temp) {
                    minnum = temp;
                    if (arr[0] == 0) {
                        minzero = 1;
                    }
                    else {
                        minzero = 0;
                    }
                }
            }
        } while(next_permutation(arr,arr+K+1));
    } while(prev_permutation(subarr,subarr+10));

    if (maxzero == 1) {
        cout << '0';
    }
    cout << maxnum << endl;
    if (minzero == 1) {
        cout << '0';
    }
    cout << minnum << endl;
    
    return 0;
}
