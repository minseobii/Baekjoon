#include <iostream>
#include <queue>
using namespace std;
int N,M;
bool ans = true;
int custom[1000001];
bool arr[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    for (int i=0;i<N;i++) {
        cin >> custom[i];
        arr[custom[i]] = true;
    }

    int t = 0;
    int rabbit = 0;

    for (int i=0;i<N;i++) {
        if (t < custom[i]) {
            while(t < custom[i]-M) {
                if (arr[t] == false) rabbit++;
                t++;
            }

            if (rabbit) {
                while(t < custom[i]) {
                    if (arr[t] == false) {
                        break;
                    }
                    t++;
                }

                if (t < custom[i]) {
                    t++;
                    rabbit--;
                }
                else {
                    ans = false;
                    break;
                }
            }
            else {
                while(t < custom[i]) {
                    if (arr[t] == false) {
                        rabbit++;
                        t++;
                        break;
                    }
                    t++;
                }

                while(t < custom[i]) {
                    if (arr[t] == false) {
                        break;
                    }
                    t++;
                }

                if (t < custom[i]) {
                    t++;
                    rabbit--;
                }
                else {
                    ans = false;
                    break;
                }
            }
        }

        else {
            ans = false; 
            break;
        }
    }

    if (ans == true) cout << "success";
    else cout << "fail";

    return 0;
}
