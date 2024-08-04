#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void solve(int root, int end) {
    if (root >= end) {
        return;
    }
    int i;
    for (i=root+1;i<end;i++) {
        if (v[root] < v[i]) {
            break;
        }
    }

    solve(root+1, i);
    solve(i, end);
    cout << v[root] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int input;
    while(cin >> input) {
        v.push_back(input);
    }

    solve(0,v.size());
    return 0;
}
