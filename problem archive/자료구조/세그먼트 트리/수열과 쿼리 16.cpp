#include <iostream>
#define INF 1000000001
using namespace std;
int N,M;
int arr[1000001];
pair<int,int> segtree[4000005];

pair<int,int> init(int start, int end, int idx) {
    if (start == end) {
        segtree[idx].first = arr[start];
        segtree[idx].second = start;
        return segtree[idx];
    }

    int mid = (start + end) / 2;
    pair<int,int> a = init(start, mid, idx * 2);
    pair<int,int> b = init(mid+1, end, idx * 2 + 1);

    pair<int,int> minpair; 

    if (a.first == b.first) {
        if (a.second < b.second) minpair = a;
        else minpair = b;
    }
    else if (a.first < b.first) minpair = a;
    else minpair = b;

    segtree[idx].first = minpair.first;
    segtree[idx].second = minpair.second;
 
    return segtree[idx];
}

pair<int,int> replace(int start, int end, int key, int value, int idx) {
    if (start > key || end < key) return segtree[idx];

    if (start == end) {
        segtree[idx].first = value;
        segtree[idx].second = key;
        return segtree[idx];
    }

    int mid = (start + end) / 2;
    pair<int,int> a = replace(start,mid,key,value,idx*2);
    pair<int,int> b = replace(mid+1,end,key,value,idx*2+1);



    pair<int,int> pair;
    if (a.first == b.first) {
        if (a.second < b.second) pair = a;
        else pair = b;
    }
    else if (a.first < b.first) pair = a;
    else pair = b;
    segtree[idx] = pair;

    return segtree[idx];
}

pair<int,int> query(int start, int end, int left, int right, int idx) {
    if (left > end || right < start) return {INF,INF};
    if (left <= start && end <= right) return segtree[idx];

    int mid = (start + end) / 2;
    pair<int,int> a = query(start,mid,left,right,idx*2);
    pair<int,int> b = query(mid+1,end,left,right,idx*2+1);

    pair<int,int> ans;

    if (a.first == b.first) {
        if (a.second < b.second) ans = a;
        else ans = b;
    }
    else if (a.first < b.first) ans = a;
    else ans = b;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    init(1,N,1);

    cin >> M;
    for (int i=0;i<M;i++) {
        int a,b,c;
        cin >> a >> b >> c;

        if (a == 1) {
            replace(1,N,b,c,1);
        }
        else if (a == 2) {
            cout << query(1,N,b,c,1).second << '\n';
        }
    }
    return 0;
}
