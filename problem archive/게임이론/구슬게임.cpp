#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int b1,b2,b3,k1,k2,cache[501][501];

bool dp(int x, int y) {
    if (cache[x][y] != -1) return cache[x][y];

    int &ret = cache[x][y];
    ret = false;

    if (b1 <= x && !dp(x-b1,y)) {
        ret = true;
        return ret;
    }
    if (b2 <= x && !dp(x-b2,y)) {
        ret = true;
        return ret;
    }
    if (b3 <= x && !dp(x-b3,y)) {
        ret = true;
        return ret;
    }
    
    if (b1 <= y && !dp(x,y-b1)) {
        ret = true;
        return ret;
    }
    if (b2 <= y && !dp(x,y-b2)) {
        ret = true;
        return ret;
    }
    if (b3 <= y && !dp(x,y-b3)) {
        ret = true;
        return ret;
    }

    ret = false;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> b1 >> b2 >> b3;

    memset(cache,-1,sizeof(cache));
    for (int i=0;i<5;i++) {
        cin >> k1 >> k2;
        if (dp(k1,k2)) cout << 'A' << '\n';
        else cout << 'B' << '\n';
    }
    return 0;
}
