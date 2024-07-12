#include <iostream>
using namespace std;
int N,score,P;
int ans=-1;
int main() {
    cin >> N >> score >> P;

    if (N == 0) {
        ans = 1;
    }
    else {
        int arr[N];
        int scorearr[N];
        for (int i=0;i<N;i++) {
            cin >> arr[i];
        }
        for (int i=0;i<P;i++) {
            if (N == i) {
              if (arr[i-1] == score) {
                ans = scorearr[i-1];
              }
              else {
                ans = i+1;
              }
              break;
            }
          
            if (i == 0) {
                if (score > arr[0]) {
                    ans = 1;
                    break;
                }
                else {
                    scorearr[0] = 1;
                }
            }

            else {
                if (score > arr[i]) {
                    if (score == arr[i-1]) {
                        ans = scorearr[i-1];
                    }
                    else {
                        ans = i+1;
                    }
                    break;
                }
                else {
                    if (arr[i] == arr[i-1]) {
                        scorearr[i] = scorearr[i-1];
                    }
                    else {
                        scorearr[i] = i+1;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
