#include <iostream>
#include <map>
using namespace std;
int T;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--) {
        int N,ans;
        cin >> N;

        ans = N;
        int arr[100001] = {0,};

        for (int i=1;i<=N;i++) {
            cin >> arr[i];
        }

        for (int i=1;i<=N;i++) {
            if (arr[i] == 0) continue;

            map<int,int> m;
            int select = arr[i];
            m[i] = 1;

            
            while(arr[select]) {
                if (m[select] == 1) {
                    m[select] = 2;
                    break;
                }
                m[select] = 1;
                select = arr[select];
            }
            if (select == i) {
                for (auto iter = m.begin(); iter != m.end(); iter++) {
                    if (iter->second) {
                        arr[iter->first] = 0;
                        ans--;
                    }
                }
            }
            else if (m[select] == 2) {
                int s;
                int temp = arr[i];
                bool find = false;
                arr[i] = 0;
                while(arr[temp]) {
                    if (temp == select) {
                        find = true;
                    }

                    if (find) {
                        s = temp;
                        temp = arr[temp];
                        arr[s] = 0;
                        ans--;
                    }
                    else {
                        s = temp;
                        temp = arr[temp];
                        arr[s] = 0;
                    }
                }
            }
            else {
                arr[i] = 0;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
