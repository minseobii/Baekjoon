#include <iostream>
using namespace std;
int N;
int ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int A,B,C;
    int a,b,c;
    for (int i=0;i<N;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        if (i==0) {
            A = x;
            B = y;
            C = z;

            a = x;
            b = y;
            c = z;
        }
        else {
            int pA = A;
            int pB = B;
            int pC = C;
            int pa = a;
            int pb = b;
            int pc = c;
            A = max(pA,pB)+x;
            B = max(max(pA,pB),pC)+y;
            C = max(pB,pC)+z;

            a = min(pa,pb)+x;
            b = min(min(pa,pb),pc)+y;
            c = min(pb,pc)+z;
        }
    }
    cout << max(max(A,B),C) << ' ' << min(min(a,b),c) << endl;
    return 0;
}
