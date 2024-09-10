#include <iostream>
#define INF 1000000001
using namespace std;
int N,M,ans;
int arr[100001];
int tree_max[400000];
int tree_min[400000];

int init_min(int start, int end, int idx) {
    if (start == end) tree_min[idx] = arr[start];
    else {
        int mid = (start + end) / 2;
        tree_min[idx] = min(init_min(start,mid,idx*2), init_min(mid+1,end,idx*2+1)); 
    }
    return tree_min[idx];
}

int init_max(int start, int end, int idx) {
    if (start == end) tree_max[idx] = arr[start];
    else {
        int mid = (start + end) / 2;
        tree_max[idx] = max(init_max(start,mid,idx*2), init_max(mid+1,end,idx*2+1)); 
    }
    return tree_max[idx];
}

int query_min(int start, int end, int idx, int left, int right) {
    if (right < start || end < left) return INF;
    if (left <= start && end <= right) return tree_min[idx];

    int mid = (start + end) / 2;
    return min(query_min(start,mid,idx*2,left,right), query_min(mid+1,end,idx*2+1,left,right));
}

int query_max(int start, int end, int idx, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree_max[idx];

    int mid = (start + end) / 2;
    return max(query_max(start,mid,idx*2,left,right), query_max(mid+1,end,idx*2+1,left,right));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    init_min(1,N,1);
    init_max(1,N,1);

    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        cout << query_min(1,N,1,a,b) << ' ';
        cout << query_max(1,N,1,a,b) << '\n';
    }
    return 0;
}
