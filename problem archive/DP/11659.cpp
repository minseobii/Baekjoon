#include <iostream>
using namespace std;
int N, M;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    int sumarr[N+1] = {0,};

    for (int i=1;i<N+1;i++) {
        int temp;
        cin >> temp;

        if (i == 1) {
            sumarr[i] = temp;
        }
        else {
            sumarr[i] = temp + sumarr[i-1];
        }
    }

    for (int i=0;i<M;i++) {
        int start, end;
        cin >> start >> end;
        cout << sumarr[end] - sumarr[start-1] << '\n';
    }
    return 0;
}
