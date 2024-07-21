#include <iostream>
using namespace std;
int N;
int ans=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int arr[N] = {0,};
    
    int Fruit1 = 0;
    int Fruit2 = 0;

    int Type = 0;
    int Num = 0;

    int Left = 0;

    for (int i=0;i<N;i++) {
        cin >> arr[i];
    } 

    for (int i=0;i<N;i++) {
        if (Fruit1 == arr[i] || Fruit2 == arr[i]) {
            Num++;
        }
        else if (Type == 0 || Type == 1) {
            Type++;
            Num++;
            if (Type == 0) {
                Fruit1 = arr[i];
            }
            else {
                Fruit2 = arr[i];
            }
        }
        else {
            Fruit1 = arr[i-1];
            Fruit2 = arr[i];
            int idx = i;
            Num = 0;
            while (arr[idx] == Fruit1 || arr[idx] == Fruit2) {
                Num++;
                idx--;
            }
        }
        ans = max(ans, Num);
    }

    cout << ans << endl;
    return 0;
}
