#include <iostream>
#include <queue>
using namespace std;

long long A,B;

struct PAIR{
    long long i,depth;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    queue<PAIR> q;          
    PAIR pair = {A,1};
    q.push(pair);

    int ans = -1;

    while (!q.empty()) {

        long long x = q.front().i;
        int depth = q.front().depth;
        q.pop();

        long long nx = x * 2;
        if (nx == B) {
            ans = depth+1;
            break;
        }
        else if (nx > B) {
            continue;
        }
        else {
            PAIR newpair = {nx, depth+1};
            q.push(newpair);
        }

        nx = (x * 10) + 1;
        if (nx == B) {
            ans = depth+1;
            break;
        }
        else if (nx > B) {
            continue;
        }
        else {
            PAIR newpair = {nx, depth+1};
            q.push(newpair);
        }
    }

    cout << ans << endl;
    return 0;
}