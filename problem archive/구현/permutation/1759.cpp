#include <iostream>
#include <algorithm>
using namespace std;
int L,C;
char arr[20];

int testcorrect(char arr[],int N) {
    int C=0;
    int V=0;
    for (int i=0;i<N;i++) {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            V++;
        }
        else {
            C++;
        }
    }

    if (C > 1 && V > 0) {
        return 1;
    }
    return 0;
}

int main() {
    cin >> L >> C;
    
    for (int i=0;i<C;i++) {
        cin >> arr[i]; 
    }

    sort(arr,arr+C);

    int temp[C];
    for (int i=0;i<C;i++){
        if (i < L) temp[i] = 1;
        else temp[i] = 0;
    }
 
    do {
        char temparr[L];
        int idx=0;
        for (int i=0;i<C;i++) {
            if (temp[i] == 1) {
              temparr[idx++] = arr[i];
            }
        }
        if (testcorrect(temparr, L)) {
            for (int i=0;i<L;i++) {
                cout << temparr[i] << ' ';
            }
            cout << endl;
        }
    } while(prev_permutation(temp,temp+C));

    return 0;
}
