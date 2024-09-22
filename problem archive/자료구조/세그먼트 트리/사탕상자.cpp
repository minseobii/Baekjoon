#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int N;
int tree[4000000];

void update(int start, int end, int key, int value, int idx) {
    tree[idx] += value;
    if (start == end) return;

    int mid = (start + end) / 2;
    if (key <= mid) update(start,mid,key,value,idx*2);
    else update(mid+1,end,key,value,idx*2+1);
}

int query(int start, int end, int value, int idx) {
    if (start == end) return start;

    int ret;
    int mid = (start + end) / 2;
    int left = tree[idx*2];

    if (value <= left) ret = query(start,mid,value,idx*2);
    else ret = query(mid+1,end,value-left,idx*2+1);

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    while(N--) {
        int a,b,c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            int ret = query(1,1000000,b,1);
            update(1,1000000,ret,-1,1);
            cout << ret << '\n';
        }
        else {
            cin >> b >> c;
            update(1,1000000,b,c,1);
        }
    }
    return 0;
}
