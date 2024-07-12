#include <iostream>
#include <cmath>
using namespace std;
int N,r,c;
int ans=0;

int dy[4] = {0,0,1,1};
int dx[4] = {0,1,0,1};

bool zfunc(int n, int i, int j) {
    if (n==1) {
        for (int k=0;k<4;k++) {
            int ni = i + dy[k];
            int nj = j + dx[k];            
            if (ni == r && nj == c) {
                return true;
            }
            else {
                ans++;
            }
        }
    }
    else {
        int temp = pow(2,n-1);
        if (r < i+temp && c < j+temp) {
            if (zfunc(n-1,i,j)) return true; 
        }
        else if (r < i+temp && c >= j+temp) {
            ans += temp * temp;
            if (zfunc(n-1,i,j+temp)) return true;
        }
        else if (r >= i+temp && c < j+temp) {
            ans += 2 * temp * temp;
            if (zfunc(n-1,i+temp,j)) return true;
        }
        else if (r >= i+temp && c >= j+temp) {
            ans += 3 * temp * temp;
            if (zfunc(n-1,i+temp,j+temp)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> r >> c;

    zfunc(N,0,0);

    cout << ans << endl;
    return 0;
}
