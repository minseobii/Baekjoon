#include <iostream>
using namespace std;
int L,C;
char arr[20];

void swap(char arr[] ,int a, int b) {
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp
}

void sort(char arr[],int N) {
    for (int i=0;i<N;i++) {
        int min = i;
        for (int j=i+1;j<N;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr,i,min);
    }
}

int main() {
    cin >> L >> C;
    
    for (int i=0;i<C;i++) {
        cin >> arr[i]; 
    }

    sort(arr,C);

    cout << ans << endl;
    return 0;
}
