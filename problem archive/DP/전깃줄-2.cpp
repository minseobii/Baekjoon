#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N,M,ans;
int arr[500001];
int subarr[500001];
int LIS[500001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;
    for (int i=0;i<M;i++) {
        int a,b;
        cin >> a >> b;
        arr[a] = b;
        subarr[b] = a;
        N = max(N,a);
    }

    map<int,int> backtracking;
    map<int,bool> connect;
    int count = 1;
    for (int i=1;i<=N;i++) {
        if (arr[i] == 0) continue;
        int u = upper_bound(LIS,LIS+count,arr[i]) - LIS;

        LIS[u] = arr[i];
        backtracking[arr[i]] = LIS[u-1];
        if (count == u) count++; 
    }

    cout << M - (count - 1) << '\n';

    int k = LIS[count-1];
    while(backtracking[k]) {
        connect[subarr[k]] = true;
        k = backtracking[k];
    }
    connect[subarr[k]] = true;
    
    for (int i=1;i<=N;i++) {
        if (connect[i] == true || arr[i] == 0) continue;
        cout << i << '\n';
    }
    return 0;
}
