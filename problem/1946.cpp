#include <iostream>
using namespace std;
int T,N;
int main() {
    cin >> T;
        for (int t=0;t<T;t++) {
            int N;
            int ans=0;
            int minscore;
            int arr[100005] = {0,};
            cin >> N;
            
            for (int i=0;i<N;i++) {
                int a,b;
                cin >> a >> b;
                arr[a] = b;
                if (a == 1) {
                    minscore = b;
                    ans++;
                }
            }
            for (int i=2;i<N+1;i++) {
                if (arr[i] < minscore) {
                    ans++;
                    minscore = arr[i];
                }
            }
            cout << ans << endl;
        }
    return 0; 
}
