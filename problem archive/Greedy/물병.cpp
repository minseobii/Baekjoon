#include <iostream>
using namespace std;
int N,K,ans;

int bottle[25];
bool binary[25];

int tobinary(int n) {
    int ret = 0;
    for (int i=24;i>=0;i--) {
        binary[i] = 0;
        binary[i] = (n >> i) & 1;
        ret += binary[i];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K; 

    int num = tobinary(N);

    if (num > K) {
        while(num > K) {    
            int idx = 0;
            ans++;
            while(binary[idx] == 1) {
                binary[idx] = 0;
                num--;
                idx++;
            }

            binary[idx] = 1;
            num++;
        } 
    }

    cout << ans << endl;
    return 0;
}
