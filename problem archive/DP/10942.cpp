#include <iostream>
using namespace std;
int N,M;
int s[2005];
int OddPal[2005];
int EvenPal[2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    for (int i=1;i<=N;i++) {
        cin >> s[i];
    }

    for (int i=1;i<=N;i++) {
        int left = i-1;
        int right = i+1;
        while(left > 0 && right <=N) {
            if (s[left] == s[right]) {
                OddPal[i]++;
                left--;
                right++;
            }
            else {
                break;
            }
        }
    }

    for (int i=1;i<N;i++) {
        int left = i-1;
        int right = i+2;
        if (s[i] == s[i+1]) {
            EvenPal[i]++;
            while(left > 0 && right <= N) {
                if (s[left] == s[right]) {
                    EvenPal[i]++;
                    left--;
                    right++;
                }
                else {
                    break;
                }
            }
        }
    }
    cin >> M;
    for (int i=1;i<=M;i++) {
        int S,E,Dif,Pal;
        cin >> S >> E;
        if ((S+E)%2 == 0) {
            Dif = (E - S) / 2;
            Pal = OddPal[S+Dif];
            if (Pal >= Dif) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            Dif = (E - S - 1) / 2;
            Pal = EvenPal[S+Dif];
            if (Pal > Dif) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}
